$_ = <STDIN>; my ($n) = split;
$_ = <STDIN>; my @A = split;

$odd = 0;
$even = 0;
for($i=0; $i < $n ; $i=$i+1){
    
	if( $A[$i] %2 == 0){
	    $even = $even+1;
	}else{
	    $odd = $odd+1;
	}
}

$mn = $odd;
if ($even < $mn) {
    $mn = $even;
}

$df = $odd - $mn;
$kk = $df / 3;
$qq = int($kk);
$ans = $mn + $qq;

print "$ans\n"