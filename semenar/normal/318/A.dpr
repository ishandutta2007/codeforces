program NewNumbersOrder;
var n, k: int64;
begin
readln(n,k);
if (k<=((n+1) div 2)) then writeln(2*k-1) else writeln(2*(k-((n+1) div 2)));
end.