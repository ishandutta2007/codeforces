program MKAD;
var n, m, cur, last, i: integer;
sum: int64;
begin
readln(n,m);
sum:=0;
last:=1;
for i:=1 to m do
  begin
  read(cur);
  sum:=sum+((cur-last+n) mod n);
  last:=cur;
  end;
writeln(sum);
end.