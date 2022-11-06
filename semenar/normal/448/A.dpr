program Bizon;
var a1, a2, a3, b1, b2, b3, n: integer;
begin
readln(a1,a2,a3);
readln(b1,b2,b3);
readln(n);
if (n>=(((a1+a2+a3+4) div 5)+((b1+b2+b3+9) div 10))) then writeln('YES') else writeln('NO');
end.