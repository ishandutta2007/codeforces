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
  d, k, ans : int64;
  a : array[0..2001] of int64;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n, d);
  for i := 1 to n do
    read(a[i]);
  ans := 0;
  for i := 2 to n do
    if a[i - 1] >= a[i] then begin
      k := (a[i - 1] - a[i]) div d + 1;
      a[i] := a[i] + k * d;
      ans := ans + k;
    end;
  writeln(ans);
end.