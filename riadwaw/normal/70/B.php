<?php
$n = (int)fgets(STDIN,1111);
$text=trim(fgets(STDIN,11111));

function a($str){
    return strlen(trim($str))+1;
}
$otr = array_map('a', preg_split('~[.?!]~',$text));
$cnt=0;
$last=$n;
foreach($otr as $cur){
    if($cur<2)
        continue;
    if($cur>$n){
        exit('Impossible');
    }
    if($cur+1+$last<=$n)
        $last+=$cur+1;
    else{
        ++$cnt;
        $last=$cur;
    }
}
print $cnt;