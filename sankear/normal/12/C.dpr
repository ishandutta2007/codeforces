program codeforces;

{$APPTYPE CONSOLE}

uses
  SysUtils;

const
  maxn = 100;
  maxm = 100;

var
  n, m, k, i, j, min, max : integer;
  fl : boolean;
  a : array[1..maxn] of integer;
  s : array[1..maxm] of string;
  kol : array[1..maxm] of integer;

procedure sort1(l, r : integer);
var x, t, i, j : integer;
begin
  x := a[l + random(r - l + 1)];
  i := l;
  j := r;
  while i <= j do begin
    while a[i] < x do
      inc(i);
    while a[j] > x do
      dec(j);
    if i <= j then begin
      t := a[i];
      a[i] := a[j];
      a[j] := t;
      inc(i);
      dec(j);
    end;
  end;
  if i < r then
    sort1(i, r);
  if j > l then
    sort1(l, j);
end;

procedure sort2(l, r : integer);
var x, t, i, j : integer;
begin
  x := kol[l + random(r - l + 1)];
  i := l;
  j := r;
  while i <= j do begin
    while kol[i] > x do
      inc(i);
    while kol[j] < x do
      dec(j);
    if i <= j then begin
      t := kol[i];
      kol[i] := kol[j];
      kol[j] := t;
      inc(i);
      dec(j);
    end;
  end;
  if i < r then
    sort2(i, r);
  if j > l then
    sort2(l, j);
end;

begin
  //reset(input, 'input.txt');
  //rewrite(output, 'output.txt');
  readln(n, m);
  for i := 1 to n do
    read(a[i]);
  readln;
  sort1(1, n);
  k := 0;
  for i := 1 to m do begin
    readln(s[k + 1]);
    fl := false;
    for j := 1 to k do
      if s[j] = s[k + 1] then begin
        inc(kol[j]);
        fl := true;
        break;
      end;
    if not fl then begin
      inc(k);
      kol[k] := 1;
    end;
  end;
  sort2(1, k);
  min := 0;
  for i := 1 to k do
    min := min + a[i] * kol[i];
  max := 0;
  for i := 1 to k do
    max := max + a[n - i + 1] * kol[i];
  write(min, ' ', max);
end.