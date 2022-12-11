<?php
 list($n) = explode(" ", fgets(STDIN));
 $n = (int) $n;
 $s = (int)7;
 $o = (int)1;
 if ($n % 2 == 1) 
  echo $s;
 else
  echo $o;
 for ($i = 1; $i * 2 < $n - $n % 2; $i++)
  echo $o; 
?>