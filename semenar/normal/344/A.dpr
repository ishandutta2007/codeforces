program Magnetism;
var last, i, n, cur, sum: integer;
begin
readln(n);
sum:=1;
read(last);
for i:=2 to n do
  begin
  read(cur);
  if (cur <> last) then sum:=sum+1;
  last:=cur;
  end;
writeln(sum);
end.