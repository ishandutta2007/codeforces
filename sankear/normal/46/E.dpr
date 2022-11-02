program solution;

{$APPTYPE CONSOLE}
{$MAXSTACKSIZE 100000000}
{$O+,R-,Q-}

uses
  SysUtils,
  Math;

const
  inf = 1000000000000000;

var
  n, m, i, j : integer;
  a, sum, d, ld, rd : array[0..1501, 0..1501] of int64;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n, m);
  for i := 1 to n do
    for j := 1 to m do
      read(a[i, j]);
  for i := 1 to n do
    for j := 1 to m do
      sum[i, j] := sum[i, j - 1] + a[i, j];
  for i := 1 to n do begin
    for j := 1 to m do
      if i mod 2 = 1 then
        d[i, j] := max(sum[i, j] + ld[i - 1, j - 1], -inf)
      else
        d[i, j] := max(sum[i, j] + rd[i - 1, j + 1], -inf);
    ld[i, 0] := -inf;
    for j := 1 to m do
      ld[i, j] := max(ld[i, j - 1], d[i, j]);
    rd[i, m + 1] := -inf;
    for j := m downto 1 do
      rd[i, j] := max(rd[i, j + 1], d[i, j]);
  end;
  write(ld[n, m]);
end.