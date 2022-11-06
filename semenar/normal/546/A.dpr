program Bananas;
var k, n, w, sum: integer;
begin
readln(k, n, w);
sum:=k*((w*(w+1)) div 2);
if n >= sum then writeln(0) else writeln(sum-n);
end.