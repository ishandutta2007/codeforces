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
  eps = 1e-9;
  inf = 1e9;

var
  n, v, i : integer;
  sum, ans : extended;
  a, b : array[0..21] of integer;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n, v);
  for i := 1 to n do
    read(a[i]);
  for i := 1 to n do
    read(b[i]);
  sum := 0;
  for i := 1 to n do
    sum := sum + a[i];
  ans := v / sum;
  for i := 1 to n do
    ans := min(ans, b[i] / a[i]);
  ans := ans * sum;
  writeln(ans:0:9);
end.