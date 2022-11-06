program Mathematics;
var n: integer;
begin
readln(n);
if (n mod 2) = 0 then writeln(4,' ',n-4) else writeln(9,' ',n-9);
end.