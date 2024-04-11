var   n: longint;
      i, k, j, m, f, s: longint;
      a: array[-10..1000005] of integer;

begin

read(n);
a[0] := 1;
for i := 1 to n do if (a[i - 4] = 1)or(a[i - 7] = 1) then a[i] := 1;
if a[n] = 0 then write('-1')else
begin
  k := 0;
  m := n mod 7;
  s := 0;
  while k <> m do
  begin
    k := (k + 4) mod 7;
    s := s + 4;
    write(4);
  end;
for i := 1 to (n - s)div 7 do write(7);
end;
end.