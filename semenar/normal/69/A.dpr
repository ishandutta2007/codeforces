program Vasya;
var x, y, z, x1, y1, z1, n, i: integer;
begin
readln(n);
x:=0;
y:=0;
z:=0;
for i:=1 to n do
  begin
  readln(x1,y1,z1);
  x:=x+x1;
  y:=y+y1;
  z:=z+z1;
  end;
if (x=0) and (y=0) and (z=0) then writeln('YES') else writeln('NO');
end.