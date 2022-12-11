var o: array[1..200] of longint;
    n, k, m, s, i, j, u, no: longint;
begin
k := 0;
read(n);
for i := 1 to n do
begin
  read(s);
  if s > 0 then begin write(s,' '); u := 1; end;
  if s < 0 then begin inc(k); o[k] := s; end;
  if s = 0 then no := 1;
end;
for i := 1 to k - 1 do for j := 1 to k - i do
if o[j] > o[j+1] then begin
m := o[j]; o[j] := o[j+1]; o[j+1] := m;
end;
for i := 1 to (k div 2) * 2 do write(o[i],' ');
if (u = 0)and(k div 2 = 0) then if (no = 1) then write(0) else
write(o[1]);
end.