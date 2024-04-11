const eps = 0.000001;
var km, kb, kt: extended;
    a: array[1..1000] of longint;
    kol, n, k, t, m, p, s, i, j: longint;
begin

read(n, k, t);
kol := 0;
km := 100 / (n * k);
kb := 100 / n;
while kt + kb - eps < t do
begin
  kt := kt + kb;
  inc(kol);
  a[kol] := k;
end;
inc(kol);

while kt + km - eps < t do
begin
  kt := kt + km;
  inc(a[kol]);
end;

for i := 1 to n do write(a[i], ' ');
end.