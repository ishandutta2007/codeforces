program solution;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Math;

var
  n, i : integer;
  a : array[1..100] of integer;

procedure sort(l, r : integer);
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
    sort(i, r);
  if j > l then
    sort(l, j);
end;

begin
  //reset(input, 'input.txt');
  //rewrite(output, 'output.txt');
  read(n);
  for i := 1 to n do
    read(a[i]);
  sort(1, n);
  for i := 2 to n do
    if a[i] > a[i - 1] then begin
      write(a[i]);
      halt(0);
    end;
  write('NO');
end.