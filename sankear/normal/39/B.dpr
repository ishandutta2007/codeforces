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
  n, k, i : integer;
  a, num : array[0..101] of integer;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n);
  for i := 1 to n do
    read(a[i]);
  k := 0;
  for i := 1 to n do
    if a[i] = k + 1 then begin
      inc(k);
      num[k] := i;
    end;
  writeln(k);
  for i := 1 to k do
    write(2000 + num[i], ' ');
  writeln;
end.