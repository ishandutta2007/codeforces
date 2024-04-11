program solution;

{$APPTYPE CONSOLE}
{MODE DELPHI}
{$MAXSTACKSIZE 1000000000}
{O-,R+,Q+}
{$O+,R-,Q-}

uses
  SysUtils,
  Math;

const
  eps = 1e-9;
  inf = round(1e15);

var
  x, y, k, kol, f, aa, bb, i, j : integer;
  w, sum, res, ans : int64;
  ca, cb : array[0..200001] of integer;
  a, b, c, r : array[0..200001] of double;

function eq(a, b : double) : boolean;
begin
  result := abs(a - b) < eps;
end;

function less(a, b : double) : boolean;
begin
  result := b - a >= eps;
end;

function rev(a : integer) : integer;
begin
  result := 0;
  while a > 0 do begin
    result := result * 10 + a mod 10;
    a := a div 10;
  end;
end;

procedure sort(l, r : integer);
var ec, t : double;
i, j : integer;
begin
  if l >= r then
    exit;
  ec := c[l + random(r - l + 1)];
  i := l;
  j := r;
  while i <= j do begin
    while less(c[i], ec) do
      inc(i);
    while less(ec, c[j]) do
      dec(j);
    if i <= j then begin
      t := c[i];
      c[i] := c[j];
      c[j] := t;
      inc(i);
      dec(j);
    end;
  end;
  sort(i, r);
  sort(l, j);
end;

function find(fc : double) : integer;
var l, r, mid : integer;
begin
  result := 0;
  l := 1;
  r := kol;
  while l <= r do begin
    mid := l + (r - l) div 2;
    if eq(c[mid], fc) then begin
      result := mid;
      exit;
    end;
    if less(c[mid], fc) then
      l := mid + 1
    else
      r := mid - 1;
  end;
end;

begin
  randomize;
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(x, y, w);
  k := 0;
  for i := 1 to max(x, y) do
    r[i] := rev(i);
  for i := 1 to x do begin
    a[i] := i / r[i];
    inc(k);
    c[k] := a[i];
  end;
  for i := 1 to y do begin
    b[i] := r[i] / i;
    inc(k);
    c[k] := b[i];
  end;
  sort(1, k);
  kol := 1;
  for i := 2 to k do
    if less(c[i - 1], c[i]) then begin
      inc(kol);
      c[kol] := c[i];
    end;
  for i := 1 to y do
    inc(cb[find(b[i])]);
  ans := inf;
  sum := 0;
  j := y;
  for i := 1 to x do begin
    f := find(a[i]);
    inc(ca[f]);
    sum := sum + cb[f];
    while (j > 1) and (sum >= w) do begin
      f := find(b[j]);
      if sum - ca[f] >= w then begin
        dec(j);
        dec(cb[f]);
        sum := sum - ca[f];
      end
      else
        break;
    end;
    if sum >= w then begin
      res := i * j;
      if res < ans then begin
        ans := res;
        aa := i;
        bb := j;
      end;
    end;
  end;
  if ans = inf then
    writeln(-1)
  else
    writeln(aa, ' ', bb);
end.