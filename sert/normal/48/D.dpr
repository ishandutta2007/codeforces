program foto;

{$APPTYPE CONSOLE}

var n, i, j, k, m, p, s,c, d, bs, nm, epic_fail, max: longint;
    a, kol, st: array[1..100000] of longint;
    b: array[-601..601] of integer;
begin
//reset(input,'photo.in');
//rewrite(output,'photo.out');
read(n);
for i := 1 to n do begin
read(a[i]);
inc(kol[a[i]]); if a[i] > max then max := a[i]; end;
epic_fail := 0;
for i := 1 to max-1 do
if kol[i] < kol[i+1] then
epic_fail :=324;
if epic_fail = 324 then write(-1) else
begin
  writeln(kol[1]);
  for i := 1 to n do begin inc(st[a[i]]); write(st[a[i]], ' '); end;
end;

end.