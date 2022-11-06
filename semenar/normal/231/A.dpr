program Zadachi;
var a, s, sum, i, k, n: integer;
begin
readln(n);
sum := 0;
for i:=1 to n do
  begin
  s := 0;
  for k:=1 to 3 do
    begin
    read(a);
    s := s+a;
    end;
  if (s > 1) then sum := sum+1;
  end;
writeln(sum);
end.