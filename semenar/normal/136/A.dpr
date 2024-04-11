program Podarki;
var n, i, tmp: integer;
ans: array [1..100] of integer;
begin
readln(n);
for i:=1 to n do
  begin
  read(tmp);
  ans[tmp] := i;
  end;
write(ans[1]);
for i:=2 to n do
  write(' ',ans[i]);
end.