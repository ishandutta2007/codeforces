program Rooms;
var p, q, n, i, sum: integer;
begin
readln(n);
sum:=0;
for i:=1 to n do
  begin
  readln(p,q);
  if (p+2<=q) then sum:=sum+1;
  end;
writeln(sum);
end.