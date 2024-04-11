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
  n, a, ans, i, j : integer;
  can : array[0..10001] of boolean;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n);
  can[0] := true;
  for i := 1 to n do begin
    read(a);
    for j := 10000 downto a do
      can[j] := can[j] or can[j - a];
  end;
  ans := 0;
  for i := 1 to 10000 do
    if (i mod 2 = 1) and (can[i]) then
      ans := i;
  writeln(ans);
end.