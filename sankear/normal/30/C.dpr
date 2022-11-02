program solution;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Math;

const
  eps = 0.000000001;

type
  tp = record
    x, y : integer;
    t : int64;
    p : extended;
  end;

var
  n, i, j : integer;
  t : tp;
  ans : extended;
  p : array[0..1001] of tp;
  d : array[0..1001] of extended;

function less(var a, b : tp) : boolean;
begin
  result := a.t < b.t;
end;

function can(var a, b : tp) : boolean;
begin
  result := (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) <= (a.t - b.t) * (a.t - b.t);
end;

function max(a, b : extended) : extended;
begin
  if b - a >= eps then
    result := b
  else
    result := a;
end;

begin
  //reset(input, 'input.txt');
  //rewrite(output, 'output.txt');
  read(n);
  for i := 1 to n do
    read(p[i].x, p[i].y, p[i].t, p[i].p);
  for i := 1 to n - 1 do
    for j := n downto i + 1 do
      if less(p[j], p[i]) then begin
        t := p[i];
        p[i] := p[j];
        p[j] := t;
      end;
  for i := 1 to n do begin
    d[i] := p[i].p;
    for j := 1 to i - 1 do
      if can(p[j], p[i]) then
        d[i] := max(d[i], d[j] + p[i].p);
  end;
  ans := 0;
  for i := 1 to n do
    ans := max(ans, d[i]);
  write(ans:0:9);
end.