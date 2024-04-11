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
  n, k, a, b, i, j, z : integer;
  s : string;
  can : array[0..201, 0..201] of boolean;
  prev : array[0..201, 0..201] of integer;

procedure gets(var s : string);
var c : char;
begin
  s := '';
  read(c);
  while not (c in ['a'..'z']) do
    read(c);
  while c in ['a'..'z'] do begin
    s := s + c;
    read(c);
  end;
end;

procedure wrans(n, k : integer);
var i : integer;
begin
  if prev[n, k] > 0 then
    wrans(prev[n, k], k - 1);
  for i := prev[n, k] + 1 to n do
    write(s[i]);
  writeln;
end;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(k, a, b);
  gets(s);
  n := length(s);
  can[0, 0] := true;
  for i := 1 to n do
    for j := 1 to k do
      for z := a to b do
        if (i - z >= 0) and (can[i - z, j - 1]) then begin
          can[i, j] := true;
          prev[i, j] := i - z;
          break;
        end;
  if not can[n, k] then begin
    writeln('No solution');
    halt(0);
  end;
  wrans(n, k);
end.