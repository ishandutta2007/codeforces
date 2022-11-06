program Arbuz;
var arb: integer;
begin
readln(arb);
if (arb mod 2 = 0) and ((arb - 2) > 0) then writeln('YES') else writeln ('NO');
end.