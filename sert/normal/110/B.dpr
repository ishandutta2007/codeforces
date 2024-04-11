var   n: int64;
      i, k, j, m, f: longint;
      a: array[0..4] of char;

begin
a[1] := 'a';
a[2] := 'b';
a[3] := 'c';
a[0] := 'd';
read(n);
for i := 1 to n do write(a[i mod 4]);
end.