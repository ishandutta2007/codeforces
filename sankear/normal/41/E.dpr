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
  n, l1, r1, l2, r2, i, j : integer;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n);
  l1 := 1;
  r1 := n div 2;
  l2 := n div 2 + 1;
  r2 := n;
  writeln((r1 - l1 + 1) * (r2 - l2 + 1));
  for i := l1 to r1 do
    for j := l2 to r2 do
      writeln(i, ' ', j);
end.