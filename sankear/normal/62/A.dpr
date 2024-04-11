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
  a, b, c, d : integer;
  ans : boolean;

function solve(a, b : integer) : boolean;
begin
  result := (a >= b - 1) and (b >= (a - 1) div 2);
end;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(a, b, c, d);
  ans := solve(d, a) or solve(c, b);
  if ans then
    writeln('YES')
  else
    writeln('NO');
end.