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
  n, i, j : integer;
  x, d : array[0..101] of integer;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n);
  for i := 1 to n do
    read(x[i], d[i]);
  for i := 1 to n - 1 do
    for j := i + 1 to n do
      if (x[i] + d[i] = x[j]) and (x[j] + d[j] = x[i]) then begin
        writeln('YES');
        halt(0);
      end;
  writeln('NO');
end.