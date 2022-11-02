program solution;

{$APPTYPE CONSOLE}
{MODE DELPHI}
{$MAXSTACKSIZE 1000000000}
{O-,R+,Q+}
{$O+,R-,Q-}

uses
  SysUtils,
  Math;

var
  n, maxv, res, l, r, mid, i : integer;
  ans : int64;
  a, b : array[0..1000001] of integer;
  d : array[0..1000001] of int64;
  rsq : array[0..2098001] of int64;

procedure sort(l, r : integer);
var eb, t, i, j : integer;
begin
  if l >= r then
    exit;
  eb := b[l + random(r - l + 1)];
  i := l;
  j := r;
  while i <= j do begin
    while b[i] < eb do
      inc(i);
    while eb < b[j] do
      dec(j);
    if i <= j then begin
      t := b[i];
      b[i] := b[j];
      b[j] := t;
      inc(i);
      dec(j);
    end;
  end;
  sort(i, r);
  sort(l, j);
end;

procedure add(a : integer; b : int64);
begin
  a := a + maxv - 1;
  rsq[a] := b;
  while a > 1 do begin
    a := a div 2;
    rsq[a] := rsq[a * 2] + rsq[a * 2 + 1];
  end;
end;

function rsum(l, r : integer) : int64;
begin
  result := 0;
  l := l + maxv - 1;
  r := r + maxv - 1;
  while l <= r do begin
    if l mod 2 = 1 then
      result := result + rsq[l];
    l := (l + 1) div 2;
    if r mod 2 = 0 then
      result := result + rsq[r];
    r := (r - 1) div 2;
  end;
end;

begin
  randomize;
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n);
  for i := 1 to n do begin
    read(a[i]);
    b[i] := a[i];
  end;
  sort(1, n);
  maxv := 1;
  while maxv < n do
    maxv := maxv * 2;
  for i := 1 to n do begin
    res := n + 1;
    l := 1;
    r := n;
    while l <= r do begin
      mid := l + (r - l) div 2;
      if b[mid] > a[i] then begin
        res := mid;
        r := mid - 1;
      end
      else
        l := mid + 1;
    end;
    d[i] := rsum(res, n);
    add(res - 1, 1);
  end;
  for i := 1 to 2 * maxv - 1 do
    rsq[i] := 0;
  ans := 0;
  for i := 1 to n do begin
    res := n + 1;
    l := 1;
    r := n;
    while l <= r do begin
      mid := l + (r - l) div 2;
      if b[mid] > a[i] then begin
        res := mid;
        r := mid - 1;
      end
      else
        l := mid + 1;
    end;
    ans := ans + rsum(res, n);
    add(res - 1, d[i]);
  end;
  writeln(ans);
end.