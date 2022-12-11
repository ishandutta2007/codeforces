var a: array[1..1000, 1..1000] of longint;
    n, i, j, k, s, t, q, max: longint;
begin

//reset(input,'i.i');
//rewrite(output,'o.o');

read(n);
for i := 1 to n*2 do
if i * (i-1) <= n*2 then k := i else break;
max := k-1;
for i := 1 to k-1 do a[1, i] := i;
for i := 2 to k do
begin
  for j := 1 to i-1 do a[i, j] := a[j, i-1];
  for j := i to k-1 do begin inc(max); a[i, j] := max; end;
end;
writeln(k);
for i := 1 to k do begin
for j := 1 to k-1 do write(a[i, j], ' ');
writeln; end;
end.