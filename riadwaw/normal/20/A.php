<?php
$var=fgets(STDIN,255);
$var=preg_replace('~/+~','/',$var);
$var=preg_replace("[\n\t]",'',$var);
$var=substr($var,0,-2);
while(strlen($var)>1 && $var[strlen($var)-1]=='/')
    $var=substr($var,0,-1);
    
print $var;