program solution;

{$APPTYPE CONSOLE}
{$MAXSTACKSIZE 100000000}
{$O+,R-,Q-}

uses
  SysUtils,
  Math;

var
  n, i : integer;
  a : array[0..10001] of integer;
  b : array[0..2] of integer;

function sum(a : integer) : integer;
begin
  result := 0;
  while a > 0 do begin
    result := (result + a mod 10) mod 3;
    a := a div 10;
  end;
end;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n);
  for i := 1 to n do
    read(a[i]);
  for i := 1 to n do
    inc(b[sum(a[i])]);
  write(b[0] div 2 + min(b[1], b[2]));
end.