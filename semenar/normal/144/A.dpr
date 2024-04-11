program Generalissimus;
var n, maxr, minr, i: integer;
height: array [1..100] of integer;
begin
readln(n);
for i:=1 to n do
  read(height[i]);
maxr := 1;
minr := n;
for i:=2 to n do
  if (height[i] > height[maxr]) then maxr := i;
for i:=n-1 downto 1 do
  if (height[i] < height[minr]) then minr := i;
i:=maxr-1+n-minr;
if (maxr > minr) then i:=i-1;
writeln(i);
end.