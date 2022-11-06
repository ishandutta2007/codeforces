program DoubleCola;
var n, i, cur: integer;
double_people: array [1..29] of integer;
name: array [0..4] of string;
begin
readln(n);
name[0] := 'Sheldon';
name[1] := 'Leonard';
name[2] := 'Penny';
name[3] := 'Rajesh';
name[4] := 'Howard';
n:=n-1;
cur:=1;
double_people[1]:=1;
for i:=2 to 29 do
  double_people[i]:=double_people[i-1]*2;
while n>=double_people[cur]*5 do
  begin
  n:=n-double_people[cur]*5;
  cur:=cur+1;
  end;
writeln(name[n div double_people[cur]]);
end.