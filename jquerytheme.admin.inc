<?php

/**
 * Page callback: Current posts settings
 *
 * @see current_posts_menu()
 */
function jquerytheme_form($form, &$form_state)
{

    $themes = list_themes();
    $options = array();
    foreach ($themes as $key => $value) {
        if ($value->status == 1) {
            $options[$key] = $value->name;
        }
    }

    $form['jquerytheme']['themes'] = array(
        '#type' => 'checkboxes',
        '#title' => t('Swap jQuery to a different version on these themes only'),
        '#options' => $options,
        '#default_value' => variable_get('themes', array()),
    );

    return system_settings_form($form);
}
