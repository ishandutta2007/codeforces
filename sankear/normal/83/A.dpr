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
  n, i : integer;
  ans : int64;
  a, d : array[0..100001] of integer;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n);
  for i := 1 to n do
    read(a[i]);
  for i := 1 to n do begin
    d[i] := 1;
    if (i > 1) and (a[i - 1] = a[i]) then
      d[i] := d[i] + d[i - 1];
  end;
  ans := 0;
  for i := 1 to n do
    ans := ans + d[i];
  writeln(ans);
end.