program TheMatrix;
var i, cur, j, x, y: integer;

function abs(a: integer): integer;
begin
if a>0 then abs:=a else abs:=-a;
end;

begin
for i:=1 to 5 do
  begin
  for j:=1 to 5 do
    begin
    read(cur);
    if (cur=1) then
      begin
      x:=j;
      y:=i;
      end;
    end;
  end;
writeln(abs(x-3)+abs(y-3));
end.