program solution;

{$APPTYPE CONSOLE}
{MODE DELPHI}
{$MAXSTACKSIZE 1000000000}
{O-,R+,Q+}
{$O+,R-,Q-}

uses
  SysUtils,
  Math;

type
  tp = record
    a, b : integer;
  end;

var
  n, a, b, i : integer;
  p : array[0..100001] of tp;
  ans : array[0..100001] of integer;

function less(v : integer; var a, b : tp) : boolean;
begin
  if v = 1 then begin
    if a.a = b.a then begin
      result := a.b < b.b;
      exit;
    end;
    result := a.a > b.a;
    exit;
  end;
  if a.a = b.a then begin
    result := a.b < b.b;
    exit;
  end;
  result := a.a < b.a;
end;

procedure sort(v, l, r : integer);
var ep, t : tp;
i, j : integer;
begin
  if l >= r then
    exit;
  ep := p[l + random(r - l + 1)];
  i := l;
  j := r;
  while i <= j do begin
    while less(v, p[i], ep) do
      inc(i);
    while less(v, ep, p[j]) do
      dec(j);
    if i <= j then begin
      t := p[i];
      p[i] := p[j];
      p[j] := t;
      inc(i);
      dec(j);
    end;
  end;
  sort(v, i, r);
  sort(v, l, j);
end;

begin
  randomize;
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n, a, b);
  for i := 1 to n do begin
    read(p[i].a);
    p[i].b := i;
  end;
  if a = b then begin
    for i := 1 to a do
      write('1 ');
    for i := 1 to b do
      write('2 ');
    writeln;
    halt;
  end;
  if a < b then
    sort(1, 1, n)
  else
    sort(2, 1, n);
  for i := 1 to n do
    ans[i] := 2;
  for i := 1 to a do
    ans[p[i].b] := 1;
  for i := 1 to n do
    write(ans[i], ' ');
  writeln;
end.