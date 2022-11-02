program codeforces;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Math;

const
  maxn = 5000;
  inf = 1000000000000000000;

var
  n, k, i, j : integer;
  ans : int64;
  a, b0, b : array[1..maxn] of integer;
  d0, d, fmin0, fmin : array[1..maxn] of int64;

procedure sort(l, r : integer);
var x, t, i, j : integer;
begin
  x := b0[l + random(r - l + 1)];
  i := l;
  j := r;
  while i <= j do begin
    while b0[i] < x do
      inc(i);
    while b0[j] > x do
      dec(j);
    if i <= j then begin
      t := b0[i];
      b0[i] := b0[j];
      b0[j] := t;
      inc(i);
      dec(j);
    end;
  end;
  if i < r then
    sort(i, r);
  if j > l then
    sort(l, j);
end;

begin
  //reset(input, 'input.txt');
  //rewrite(output, 'output.txt');
  read(n);
  for i := 1 to n do begin
    read(a[i]);
    b0[i] := a[i];
  end;
  sort(1, n);
  k := 1;
  b[1] := b0[1];
  for i := 2 to n do
    if b0[i] <> b0[i - 1] then begin
      inc(k);
      b[k] := b0[i];
    end;
  for i := 1 to n do begin
      for j := 1 to k do
        if j = 1 then
          fmin[1] := d0[1]
        else
          fmin[j] := min(fmin[j - 1], d0[j]);
      for j := 1 to k do
        d[j] := abs(a[i] - b[j]) + fmin[j];
      fmin0 := fmin;
      d0 := d;
  end;
  ans := inf;
  for i := 1 to k do
    ans := min(ans, d[i]);
  write(ans);
end.