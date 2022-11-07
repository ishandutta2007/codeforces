program Kefa;
var cur, last, max, l, i, n: integer;
begin
readln(n);
max := 1;
l := 1;
read(last);
for i:=2 to n do
  begin
  read(cur);
  if cur>=last then l:=l+1 else l:=1;
  if l>max then max:=l;
  last:=cur;
  end;
writeln(max);
end.