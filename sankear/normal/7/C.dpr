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
  a, b, c, g, x, y : int64;

function gcd(a, b : int64; var x, y : int64) : int64;
var xx, yy : int64;
begin
  if b = 0 then begin
    result := a;
    x := 1;
    y := 0;
    exit;
  end;
  result := gcd(b, a mod b, xx, yy);
  x := yy;
  y := xx - (a div b) * yy;
end;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(a, b, c);
  c := -c;
  g := gcd(abs(a), abs(b), x, y);
  if c mod g <> 0 then begin
    writeln(-1);
    halt;
  end;
  if a < 0 then
    x := -x;
  if b < 0 then
    y := -y;
  c := c div g;
  x := x * c;
  y := y * c;
  writeln(x, ' ', y);
end.