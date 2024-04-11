program solution;

{$APPTYPE CONSOLE}
{MODE DELPHI}
{$MAXSTACKSIZE 1000000000}
{O-,R+,Q+}
{$O+,R-,Q-}

uses
  SysUtils,
  Math;

const
  inf = round(1e9);

type
  tp = record
    a, b, c, d : integer;
  end;

var
  n, m, c, dd, ans, i, j, z : integer;
  p : array[0..11] of tp;
  d : array[0..11, 0..1001] of integer;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n, m, c, dd);
  for i := 1 to m do
    read(p[i].a, p[i].b, p[i].c, p[i].d);
  for i := 0 to m do
    for j := 0 to n do
      d[i, j] := -inf;
  d[0, n] := 0;
  for i := 0 to m - 1 do
    for j := 0 to n do begin
      if d[i, j] = -inf then
        continue;
      for z := 0 to j do
        if (p[i + 1].b * z <= p[i + 1].a) and (p[i + 1].c * z <= j) then
          d[i + 1, j - p[i + 1].c * z] := max(d[i + 1, j - p[i + 1].c * z], d[i, j] + z * p[i + 1].d);
    end;
  ans := -inf;
  for i := 0 to n do
    for j := 0 to i do
      if j * c <= i then
        ans := max(ans, d[m, i] + j * dd);
  writeln(ans);
end.