var a: array[1..101] of int64;
    i, n, k: integer;
begin
read(n);
for i := 1 to n do
begin
  read(k);
  a[k] := i;
end;
for i := 1 to n do write(a[i], ' ');
end.