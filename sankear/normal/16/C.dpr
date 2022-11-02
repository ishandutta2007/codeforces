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
  a, b, x, y, g : int64;

function gcd(a, b : int64) : int64;
var c : int64;
begin
  while b > 0 do begin
    c := b;
    b := a mod b;
    a := c;
  end;
  result := a;
end;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(a, b, x, y);
  g := gcd(x, y);
  x := x div g;
  y := y div g;
  a := min(a div x, b div y) * x;
  b := (a * y) div x;
  writeln(a, ' ', b);
end.