program Domino;
var m, n: integer;
begin
readln(m,n);
if ((m mod 2)=1) and ((n mod 2)=1) then writeln(trunc((m*n-1)/2)) else writeln(trunc(m*n/2));
end.