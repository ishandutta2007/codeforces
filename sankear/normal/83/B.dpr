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
  n, k, kol, sum, op, i, j : integer;
  kk, s, res : int64;
  a, b, sz, c : array[0..100001] of integer;

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

begin
  randomize;
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n, kk);
  for i := 1 to n do
    read(a[i]);
  for i := 1 to n do
    b[i] := a[i];
  sort(1, n);
  k := 1;
  sz[1] := 1;
  for i := 2 to n do
    if b[i - 1] < b[i] then begin
      inc(k);
      b[k] := b[i];
      sz[k] := 1;
    end
    else
      inc(sz[k]);
  sum := n;
  op := 0;
  for i := 1 to k do begin
    res := int64(b[i] - b[i - 1]) * sum;
    if res < kk then begin
      kk := kk - res;
      sum := sum - sz[i];
      op := op + b[i] - b[i - 1];
      continue;
    end;
    if res = kk then begin
      op := op + b[i] - b[i - 1];
      for j := 1 to n do
        if a[j] > op then
          write(j, ' ');
      writeln;
      halt;
    end;
    s := kk div sum;
    res := s * sum;
    if res = kk then begin
      op := op + s;
      for j := 1 to n do
        if a[j] > op then
          write(j, ' ');
      writeln;
      halt;
    end;
    op := op + s;
    kol := 0;
    for j := 1 to n do
      if a[j] > op then begin
        inc(kol);
        c[kol] := j;
      end;
    kk := kk - res;
    for j := kk + 1 to kol do
      write(c[j], ' ');
    for j := 1 to kk do
      if a[c[j]] > op + 1 then
        write(c[j], ' ');
    writeln;
    halt;
  end;
  writeln(-1);
end.