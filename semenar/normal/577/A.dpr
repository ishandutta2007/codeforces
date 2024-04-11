program Deliteli;
var n, x, i, sum: integer;
begin
  readln(n, x);
  sum := 0;
  for i:=1 to n do
    begin
    if ((x mod i) = 0) and ((x div i) <= n) then sum := sum+1;
    end;
  writeln(sum);
end.