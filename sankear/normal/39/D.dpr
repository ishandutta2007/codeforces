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
  i : integer;
  a, b : array[0..4] of integer;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  for i := 1 to 3 do
    read(a[i]);
  for i := 1 to 3 do
    read(b[i]);
  for i := 1 to 3 do
    if a[i] = b[i] then begin
      writeln('YES');
      halt(0);
    end;
  writeln('NO');
end.