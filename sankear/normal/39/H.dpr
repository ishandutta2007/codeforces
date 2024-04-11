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
  n, res, a, b, i, j : integer;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n);
  for i := 1 to n - 1 do begin
    for j := 1 to n - 1 do begin
      res := i * j;
      a := res div n;
      b := res mod n;
      if a > 0 then
        write(a);
      write(b, ' ');
    end;
    writeln;
  end;
end.