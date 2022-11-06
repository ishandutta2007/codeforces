program Pyramids;
var sum, n, k: integer;
begin
sum:=0;
k:=0;
readln(n);
while sum<=n do
  begin
  k:=k+1;
  sum:=sum+((k*(k+1)) div 2);
  end;
writeln(k-1);
end.