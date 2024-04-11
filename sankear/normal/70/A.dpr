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
  p = round(1e6) + 3;

var
  n, i : integer;
  pow : int64;
  ans : array[0..1001] of int64;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n);
  if n = 0 then begin
    writeln(1);
    halt(0);
  end;
  if n = 1 then begin
    writeln(1);
    halt(0);
  end;
  ans[0] := 0;
  ans[1] := 3;
  pow := 2;
  for i := 2 to n do begin
    ans[i] := (3 * ans[i - 1] + pow * pow) mod p;
    pow := (pow * 2) mod p;
  end;
  pow := (pow * pow) mod p - ans[n];
  if pow < 0 then
    pow := pow + p;
  writeln(pow);
end.