program MeatMe;
var min, n, a, p, i, sum: integer;
begin
readln(n);
sum:=0;
min:=101;
for i:=1 to n do
  begin
  readln(a,p);
  if p<min then min:=p;
  sum:=sum+a*min;
  end;
writeln(sum);
end.