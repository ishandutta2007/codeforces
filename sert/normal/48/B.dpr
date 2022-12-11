program foto;

{$APPTYPE CONSOLE}

var a: array[0..300, 0..300] of integer;
    n, i, j, k, m, p, s, kol, c, d, bs, nm: longint;
    b: array[-601..601] of integer;
begin
//reset(input,'photo.in');
//rewrite(output,'photo.out');
kol :=0;
read(n, m);
for i := 1 to n do for j := 1 to m do
begin
read(s);
a[i, j] := s + a[i-1, j] + a[i, j-1] - a[i-1,j-1];
end;

read(c, d);    //dec(c); dec(d);
bs := 10000;
nm := 0;
for i := 0 to n-1 do for j := 0 to m-1 do
begin
  k := 0;
  if (i + c <= n) and (j + d <= m) then
  begin
    k := a[i + c, j + d] - a[i + c, j] - a[i, j + d] + a[i, j];
    if k < bs then bs := k;
  end;
    if (i + d <= n) and (j + c <= m) then
  begin
    k := a[i + d, j + c] - a[i + d, j] - a[i, j + c] + a[i, j];
    if k < bs then bs := k;
  end;
end;
write(bs);
end.