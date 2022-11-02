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
  l, r, pow, ans, res : int64;

function f(a : int64) : int64;
var b : int64;
sz, i : integer;
begin
  b := a;
  sz := 0;
  while b > 0 do begin
    inc(sz);
    b := b div 10;
  end;
  b := 1;
  for i := 1 to sz do
    b := b * 10;
  result := a * (b - a - 1);
end;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(l, r);
  ans := max(f(l), f(r));
  pow := 1;
  while true do begin
    if pow > r then
      break;
    res := pow * 5;
    if (res >= l) and (res <= r) then
      ans := max(ans, f(res));
    pow := pow * 10;
  end;
  writeln(ans);
end.