program Tramvai;
var max, sum, n, i, a: integer;
begin
readln(n);
max := 0;
sum := 0;
for i:=1 to n do
  begin
  read(a);
  sum := sum - a;
  readln(a);
  sum := sum + a;
  if sum > max then max := sum;
  end;
writeln(max);
end.