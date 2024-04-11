var n, i, k, s, t, j: longint;
    a, u: array[1..1000] of longint;
begin
reset(input,'input.txt');
rewrite(output,'output.txt');
read(n, k);
for i := 1 to n do
read(a[i]);

for i := n downto 1 do begin
  t := a[i] mod k;
  if a[i] - k * 3 > t then t := a[i] - 3 * k;
  s := s + t;
end;
write(s);
end.