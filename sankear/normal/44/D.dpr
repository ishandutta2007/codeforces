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

var
  n, i, j : integer;
  ans, res : double;
  x, y, z, d : array[0..5001] of double;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n);
  for i := 1 to n do
    read(x[i], y[i], z[i]);
  for i := 2 to n do
    d[i] := sqrt(sqr(x[1] - x[i]) + sqr(y[1] - y[i]) + sqr(z[1] - z[i]));
  ans := inf;
  for i := 2 to n - 1 do
    for j := i + 1 to n do begin
      res := d[i] + d[j] + sqrt(sqr(x[i] - x[j]) + sqr(y[i] - y[j]) + sqr(z[i] - z[j]));
      if res < ans then
        ans := res;
    end;
  ans := ans / 2;
  writeln(ans:0:9);
end.