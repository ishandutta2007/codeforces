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
  op = 1000;

var
  n, i : integer;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n);
  for i := 1 to op do
    if (i * (i + 1)) div 2 = n then begin
      writeln('YES');
      halt(0);
    end;
  writeln('NO');
end.