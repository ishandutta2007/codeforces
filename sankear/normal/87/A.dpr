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
  a, b, t, x, y : int64;

function gcd(a, b : int64) : int64;
begin
  if b = 0 then begin
    result := a;
    exit;
  end;
  result := gcd(b, a mod b);
end;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(a, b);
  t := (a * b) div gcd(a, b);
  x := (t - 1) div a;
  y := (t - 1) div b;
  if a < b then
    y := y + 1
  else
    x := x + 1;
  if x = y then begin
    writeln('Equal');
    halt;
  end;
  if x < y then begin
    writeln('Masha');
    halt;
  end;
  writeln('Dasha');
end.