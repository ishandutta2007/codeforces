program solution;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Math;

const
  maxm = 20;

type
  tk = record
    a, b : integer;
  end;

var
  n, m, i : integer;
  ans : int64;
  k : array[1..maxm] of tk;

procedure sort(l, r : integer);
var x, t : tk;
i, j : integer;
begin
  x := k[l + random(r - l + 1)];
  i := l;
  j := r;
  while i <= j do begin
    while k[i].b > x.b do
      inc(i);
    while k[j].b < x.b do
      dec(j);
    if i <= j then begin
      t := k[i];
      k[i] := k[j];
      k[j] := t;
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
  read(n, m);
  for i := 1 to m do
    read(k[i].a, k[i].b);
  sort(1, m);
  ans := 0;
  for i := 1 to m do begin
    ans := ans + min(n, k[i].a) * k[i].b;
    n := n - min(n, k[i].a);
    if n = 0 then
      break;
  end;
  write(ans);
end.