program solution;

{$APPTYPE CONSOLE}
{MODE DELPHI}
{$MAXSTACKSIZE 1000000000}
{O-,R+,Q-}
{$O+,R-,Q-}

uses
  SysUtils,
  Math;

type
  ta = array[0..300001] of integer;

var
  n, k, k1, k2, numk, kol, i : integer;
  use : array[0..3] of integer;
  used : array[0..300001] of boolean;
  a, b, c, good, num, num1, num2 : ta;

procedure sort(var num : ta; l, r : integer);
var enum, t, i, j : integer;
begin
  if l >= r then
    exit;
  enum := num[l + random(r - l + 1)];
  i := l;
  j := r;
  while i <= j do begin
    while num[i] < enum do
      inc(i);
    while enum < num[j] do
      dec(j);
    if i <= j then begin
      t := num[i];
      num[i] := num[j];
      num[j] := t;
      inc(i);
      dec(j);
    end;
  end;
  sort(num, i, r);
  sort(num, l, j);
end;

begin
  randomize;
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n);
  for i := 1 to 3 * n do
    read(num[i]);
  for i := 1 to n do
    read(a[i], b[i], c[i]);
  read(k);
  numk := 0;
  for i := 1 to 3 * n do
    if not used[num[i]] then begin
      inc(numk);
      good[num[i]] := numk;
      used[a[numk]] := true;
      used[b[numk]] := true;
      used[c[numk]] := true;
    end;
  if good[k] > 0 then begin
    k1 := 0;
    for i := 1 to good[k] - 1 do begin
      inc(k1);
      num1[k1] := a[i];
      inc(k1);
      num1[k1] := b[i];
      inc(k1);
      num1[k1] := c[i];
    end;
    if a[good[k]] <> k then begin
      inc(kol);
      use[kol] := a[good[k]];
      inc(k1);
      num1[k1] := a[good[k]];
    end;
    if b[good[k]] <> k then begin
      inc(kol);
      use[kol] := b[good[k]];
      inc(k1);
      num1[k1] := b[good[k]];
    end;
    if c[good[k]] <> k then begin
      inc(kol);
      use[kol] := c[good[k]];
      inc(k1);
      num1[k1] := c[good[k]];
    end;
    sort(num1, 1, k1);
    for i := 1 to 3 * n do
      used[i] := false;
    i := 1;
    while i <= k1 do begin
      write(num1[i], ' ');
      used[num1[i]] := true;
      inc(i);
      if (used[use[1]]) and (used[use[2]]) then
        break;
    end;
    k2 := 0;
    while i <= k1 do begin
      inc(k2);
      num2[k2] := num1[i];
      inc(i);
    end;
    for i := good[k] + 1 to n do begin
      inc(k2);
      num2[k2] := a[i];
      inc(k2);
      num2[k2] := b[i];
      inc(k2);
      num2[k2] := c[i];
    end;
    sort(num2, 1, k2);
    for i := 1 to k2 do
      write(num2[i], ' ');
    writeln;
    halt(0);
  end;
  for i := 1 to 3 * n do
    if i <> k then
      write(i, ' ');
  writeln;
end.