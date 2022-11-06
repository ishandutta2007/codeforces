program Table;
var n, i, k: integer;
rows: array [1..10] of array [1..10] of int64;
begin
readln(n);
for i:=1 to n do
  begin
  rows[1][i]:=1;
  rows[i][1]:=1;
  end;
for i:=2 to n do
  for k:=2 to n do
    rows[i][k]:=rows[i-1][k]+rows[i][k-1];
writeln(rows[n][n]);
end.