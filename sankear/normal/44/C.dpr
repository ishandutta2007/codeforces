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
  n, m, l, r, i, j : integer;
  a : array[0..101] of integer;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n, m);
  for i := 1 to m do begin
    read(l, r);
    for j := l to r do
      inc(a[j]);
  end;
  for i := 1 to n do
    if (a[i] = 0) or (a[i] > 1) then begin
      writeln(i, ' ', a[i]);
      halt(0);
    end;
  writeln('OK');
end.