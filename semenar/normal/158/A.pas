program Second_Round;
var n, k, i, a, sum, porog: integer;
begin
readln(n,k);
sum := 0;
for i:=1 to n do
  begin
  read(a);
  if i=k then porog := a;
  if (i<k) and (a>0) then sum := sum+1;
  if i >= k then
    if (a>0) and (a=porog) then sum := sum+1;
  end;
writeln(sum);
end.