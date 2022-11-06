program Football;
var n, i, k, sum: integer;
one, another: array [1..100] of integer;
begin
readln(n);
sum:=0;
for i:=1 to n do
  readln(one[i],another[i]);
for i:=1 to n do
  for k:=1 to n do
    if one[i] = another[k] then sum:=sum+1;
writeln(sum);
end.