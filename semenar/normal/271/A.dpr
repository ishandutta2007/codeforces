program Goda;
var year: integer;

function check(a:integer):integer;
var d: array [1..4] of integer;
i: integer;
begin
for i:=1 to 4 do
  begin
  d[i]:=a mod 10;
  a:=a div 10;
  end;
if (d[1]=d[2]) or (d[1]=d[3]) or (d[1]=d[4]) or (d[2]=d[3]) or (d[2]=d[4]) or (d[3]=d[4]) then check:=0 else check:=1;
end;

begin
readln(year);
while (true) do
  begin
  year:=year+1;
  if check(year) = 1 then break;
  end;
writeln(year);
end.