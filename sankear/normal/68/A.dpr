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
  a, b, k, ans, i : integer;
  used : array[0..5] of boolean;
  p, pp : array[0..5] of integer;
  res : array[0..25, 0..5] of integer;

procedure gen(x : integer);
var i : integer;
begin
  if x > 4 then begin
    inc(k);
    for i := 1 to 4 do
      res[k, i] := p[pp[i]];
    exit;
  end;
  for i := 1 to 4 do
    if not used[i] then begin
      pp[x] := i;
      used[i] := true;
      gen(x + 1);
      used[i] := false;
    end;
end;

function good(x : integer) : boolean;
var kol, y, i, j : integer;
begin
  kol := 0;
  for i := 1 to k do begin
    y := x;
    for j := 1 to 4 do
      y := y mod res[i, j];
    if y = x then begin
      inc(kol);
      if kol >= 7 then begin
        result := true;
        exit;
      end;
    end;
  end;
  result := false;
end;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  for i := 1 to 4 do
    read(p[i]);
  read(a, b);
  k := 0;
  gen(1);
  ans := 0;
  for i := a to b do
    if good(i) then
      inc(ans);
  writeln(ans);
end.