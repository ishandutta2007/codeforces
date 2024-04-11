program solution;

{$APPTYPE CONSOLE}
{MODE DELPHI}
{$MAXSTACKSIZE 1000000000}
{O-,R+,Q+}
{$O+,R-,Q-}

uses
  SysUtils,
  Math;

var
  n, a, b, c, ans, i, j : integer;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n, a, b, c);
  ans := 0;
  for i := 0 to a do
    for j := 0 to b do
      if (i + 2 * j <= 2 * n) and ((2 * n - i - 2 * j) mod 4 = 0) and ((2 * n - i - 2 * j) div 4 <= c) then
        inc(ans);
  writeln(ans);
end.