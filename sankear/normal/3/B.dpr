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
  n, t, v, ans, res, j, a1, b1, aa, ab, i : integer;
  k : array[0..3] of integer;
  a, b, sum : array[0..3, 0..100001] of integer;

procedure swap(var a, b : integer);
var c : integer;
begin
  c := a;
  a := b;
  b := c;
end;

procedure sort(num, l, r : integer);
var ea, i, j : integer;
begin
  if l >= r then
    exit;
  ea := a[num, l + random(r - l + 1)];
  i := l;
  j := r;
  while i <= j do begin
    while a[num, i] > ea do
      inc(i);
    while ea > a[num, j] do
      dec(j);
    if i <= j then begin
      swap(a[num, i], a[num, j]);
      swap(b[num, i], b[num, j]);
      inc(i);
      dec(j);
    end;
  end;
  sort(num, i, r);
  sort(num, l, j);
end;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n, v);
  for i := 1 to n do begin
    read(t);
    inc(k[t]);
    read(a[t, k[t]]);
    b[t, k[t]] := i;
  end;
  for i := 1 to 2 do begin
    sort(i, 1, k[i]);
    for j := 1 to k[i] do
      sum[i, j] := sum[i, j - 1] + a[i, j];
  end;
  ans := 0;
  aa := 0;
  ab := 0;
  for i := 1 to min(k[1], v) do begin
    a1 := i;
    b1 := min((v - i) div 2, k[2]);
    res := sum[1, a1] + sum[2, b1];
    if res > ans then begin
      ans := res;
      aa := a1;
      ab := b1;
    end;
  end;
  for i := 1 to min(k[2], v div 2) do begin
    a1 := min(v - 2 * i, k[1]);
    b1 := i;
    res := sum[1, a1] + sum[2, b1];
    if res > ans then begin
      ans := res;
      aa := a1;
      ab := b1;
    end;
  end;
  writeln(ans);
  for i := 1 to aa do
    write(b[1, i], ' ');
  for i := 1 to ab do
    write(b[2, i], ' ');
  writeln;
end.