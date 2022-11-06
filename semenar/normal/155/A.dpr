program ILOVEUSERNAME;
var max, min, i, n, cur, sum: integer;
begin
readln(n);
read(cur);
max:=cur;
min:=cur;
sum:=0;
for i:=2 to n do
  begin
  read(cur);
  if cur>max then
    begin
    max:=cur;
    sum:=sum+1;
    end;
  if cur<min then
    begin
    min:=cur;
    sum:=sum+1;
    end;
  end;
writeln(sum);
end.