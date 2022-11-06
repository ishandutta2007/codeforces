program InfinityBerland;
var i, n: integer;
task: array [1..5000] of integer;
a: array [1..3] of integer;
num: array [1..5000] of array [1..3] of integer;

function min(a,b:integer):integer;
begin
if a>b then min:=b else min:=a;
end;

begin
readln(n);
for i:=1 to n do read(task[i]);
for i:=1 to 3 do a[i]:=0;
for i:=1 to n do
  begin
  a[task[i]]:=a[task[i]]+1;
  num[a[task[i]]][task[i]]:=i;
  end;
writeln(min(a[1],min(a[2],a[3])));
for i:=1 to min(a[1],min(a[2],a[3])) do
  writeln(num[i,1],' ',num[i,2],' ',num[i,3]);
end.