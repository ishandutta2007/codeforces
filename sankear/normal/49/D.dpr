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
  n, ans, i : integer;
  a : array[0..1001] of char;

procedure getc(var c : char);
begin
  read(c);
  while not (c in ['0'..'9']) do
    read(c);
end;

function solve(c1, c2 : char) : integer;
var i : integer;
begin
  result := 0;
  for i := 1 to n do
    if i mod 2 = 1 then begin
      if a[i] <> c1 then
        inc(result);
    end
    else begin
      if a[i] <> c2 then
        inc(result);
    end;
end;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n);
  for i := 1 to n do
    getc(a[i]);
  ans := min(solve('0', '1'), solve('1', '0'));
  writeln(ans);
end.