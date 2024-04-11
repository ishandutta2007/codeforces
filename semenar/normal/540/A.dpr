program EliteHacker;
var n, i, sum: integer;
first, second: string;

function abs(a:integer):integer;
begin
if a>0 then abs:=a else abs:=-a;
end;

begin
readln(n);
readln(first);
readln(second);
sum:=0;
for i:=1 to n do
  sum:=sum+abs(((ord(first[i])-ord(second[i])+15) mod 10)-5);
writeln(sum);
end.