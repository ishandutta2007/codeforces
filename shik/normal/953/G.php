<?php
$f = STDIN;
$n = fgets($f);
$c0 = 0;
$c1 = 0;
$a = explode(" ", trim(fgets($f)));
foreach ($a as &$x) {
    if ($x % 2 == 0) $c0++;
    else $c1++;
}
$ans = 0;
if ($c1 <= $c0) {
    $ans = $c1;
} else {
    $ans = $c0;
    $c1 -= $c0;
    $ans += (int)($c1 / 3);
}
echo $ans . "\n";
?>