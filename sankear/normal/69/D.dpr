program solution;

{$APPTYPE CONSOLE}
{MODE DELPHI}
{$MAXSTACKSIZE 1000000000}
{O-,R+,Q+}
{$O+,R-,Q-}

uses
  SysUtils,
  Math;

type
  tp = record
    x, y : integer;
  end;

var
  n, d, i : integer;
  p : tp;
  v : array[0..21] of tp;
  used, can : array[-201..201, -201..201] of boolean;

function good(x, y : integer) : boolean;
begin
  result := x * x + y * y <= d;
end;

procedure calc(x, y : integer);
var nx, ny, i : integer;
begin
  if used[x, y] then
    exit;
  used[x, y] := true;
  for i := 1 to n do begin
    nx := x + v[i].x;
    ny := y + v[i].y;
    if good(nx, ny) then begin
      calc(nx, ny);
      if not can[nx, ny] then begin
        can[x, y] := true;
        exit;
      end;
    end;
  end;
end;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(p.x, p.y, n, d);
  for i := 1 to n do
    read(v[i].x, v[i].y);
  d := d * d;
  calc(p.x, p.y);
  if can[p.x, p.y] then
    writeln('Anton')
  else
    writeln('Dasha');
end.