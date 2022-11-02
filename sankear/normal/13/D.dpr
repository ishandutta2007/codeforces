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
    x, y : int64;
  end;
  tl = record
    a, b, c : int64;
  end;

var
  n, m, ans, i, j, z : integer;
  t : tp;
  l : tl;
  a, b : array[0..501] of tp;
  f : array[0..501, 0..501] of integer;

function zn(a : int64) : integer;
begin
  if a < 0 then begin
    result := -1;
    exit;
  end;
  if a = 0 then begin
    result := 0;
    exit;
  end;
  result := 1;
end;

function getline(var a, b : tp) : tl;
begin
  result.a := a.y - b.y;
  result.b := b.x - a.x;
  result.c := a.x * b.y - b.x * a.y;
end;

function dist(var l : tl; var p : tp) : int64;
begin
  result := l.a * p.x + l.b * p.y + l.c;
end;

function more(var a, b : tp) : boolean;
begin
  result := a.x > b.x;
end;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n, m);
  for i := 1 to n do
    read(a[i].x, a[i].y);
  for i := 1 to m do
    read(b[i].x, b[i].y);
  for i := 1 to n - 1 do
    for j := n downto i + 1 do
      if more(a[i], a[j]) then begin
        t := a[i];
        a[i] := a[j];
        a[j] := t;
      end;
  for i := 1 to m - 1 do
    for j := m downto i + 1 do
      if more(b[i], b[j]) then begin
        t := b[i];
        b[i] := b[j];
        b[j] := t;
      end;
  for i := 1 to n - 1 do
    for j := i + 1 to n do begin
      l := getline(a[i], a[j]);
      for z := 1 to m do
        if (b[z].x > a[i].x) and (b[z].x <= a[j].x) and (zn(dist(l, b[z])) = 1) then
          inc(f[i, j]);
    end;
  ans := 0;
  for i := 1 to n - 2 do
    for j := i + 1 to n - 1 do
      for z := j + 1 to n do
        if f[i, j] + f[j, z] - f[i, z] = 0 then
          inc(ans);
  writeln(ans);
end.