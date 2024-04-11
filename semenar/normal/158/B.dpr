program Taxi;
var n, a, i, sum: integer;
groups: array [1..4] of integer;
begin
readln(n);
for i:=1 to 4 do groups[i] := 0;
for i:=1 to n do
  begin
  read(a);
  groups[a] := groups[a]+1;
  end;
groups[1] := groups[1] - groups[3] - 2*(groups[2] mod 2);
sum := groups[4] + groups[3] + ((groups[2]+1) div 2);
if (groups[1] > 0) then sum := sum + ((groups[1]+3) div 4);
writeln(sum);
end.