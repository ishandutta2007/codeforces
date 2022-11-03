use strict;
use warnings;

my ($n, $m) = split / /, <STDIN>;
my $i = 1;
while ($i <= $n && $i * 5 + $m <= 240){
	$m += $i * 5;
	++$i;
}
print $i - 1;