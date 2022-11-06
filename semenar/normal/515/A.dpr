program WithLove;
var a, b, x: integer;

function abs(a:integer):integer;
begin
if a>0 then abs:=a else abs:=-a;
end;

begin
readln(a, b, x);
if (abs((a+b) mod 2) = (x mod 2)) and (x>=(abs(a)+abs(b))) then writeln('Yes') else writeln('No');
end.