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
  inf = round(1e9);

var
  ans, i, j : integer;
  a, b : array[0..9, 0..9] of char;

function good(a, b : integer) : boolean;
begin
  result := (a and (1 shl (b - 1))) > 0;
end;

function calc(a : integer) : integer;
var i : integer;
begin
  result := 0;
  for i := 1 to 8 do
    if good(a, i) then
      inc(result);
end;

function check(c, d : integer) : boolean;
var i, j : integer;
begin
  for i := 1 to 8 do
    for j := 1 to 8 do
      b[i, j] := 'W';
  for i := 1 to 8 do
    if good(c, i) then begin
      for j := 1 to 8 do
        b[i, j] := 'B';
    end;
  for i := 1 to 8 do
    if good(d, i) then begin
      for j := 1 to 8 do
        b[j, i] := 'B';
    end;
  result := true;
  for i := 1 to 8 do
    for j := 1 to 8 do
      if a[i, j] <> b[i, j] then begin
        result := false;
        exit;
      end;
end;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  for i := 1 to 8 do begin
    for j := 1 to 8 do
      read(a[i, j]);
    readln;
  end;
  ans := inf;
  for i := 0 to 255 do
    for j := 0 to 255 do
      if check(i, j) then
        ans := min(ans, calc(i) + calc(j));
  writeln(ans);
end.