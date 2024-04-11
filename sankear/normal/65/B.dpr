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
  n, i, j : integer;
  a : array[0..1001] of integer;
  d : array[0..1001, 0..2012] of boolean;
  pi, pj : array[0..1001, 0..2012] of integer;

function good(a, b : integer) : boolean;
var p1, p2, k, i : integer;
begin
  p1 := 10;
  p2 := 1;
  k := 0;
  for i := 1 to 4 do begin
    if (a mod p1) div p2 <> (b mod p1) div p2 then
      inc(k);
    p1 := p1 * 10;
    p2 := p2 * 10;
  end;
  result := k <= 1;
end;

procedure wrans(x, y : integer);
begin
  if x > 0 then
    wrans(pi[x, y], pj[x, y]);
  if pi[x, y] < x then
    writeln(y);
end;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n);
  for i := 1 to n do
    read(a[i]);
  for i := 1000 to 2011 do
    d[0, i] := true;
  for i := 1 to n do
    for j := 1000 to 2011 do begin
      if d[i, j - 1] then begin
        d[i, j] := true;
        pi[i, j] := i;
        pj[i, j] := j - 1;
      end;
      if (good(a[i], j)) and (d[i - 1, j]) then begin
        d[i, j] := true;
        pi[i, j] := i - 1;
        pj[i, j] := j;
      end;
    end;
  if d[n, 2011] then
    wrans(n, 2011)
  else
    writeln('No solution');
end.