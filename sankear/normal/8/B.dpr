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
  x, y, nx, ny, i : integer;
  s : string;
  used : array[-101..101, -101..101] of boolean;
  px, py : array[-101..101, -101..101] of integer;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  readln(s);
  x := 0;
  y := 0;
  used[0, 0] := true;
  for i := 1 to length(s) do begin
    nx := x;
    ny := y;
    if s[i] = 'L' then
      dec(nx);
    if s[i] = 'R' then
      inc(nx);
    if s[i] = 'D' then
      dec(ny);
    if s[i] = 'U' then
      inc(ny);
    if used[nx, ny] then begin
      writeln('BUG');
      halt(0);
    end;
    px[nx, ny] := x;
    py[nx, ny] := y;
    used[nx, ny] := true;
    x := nx;
    y := ny;
    if (used[x - 1, y]) and ((px[x, y] <> x - 1) or (py[x, y] <> y)) then begin
      writeln('BUG');
      halt(0);
    end;
    if (used[x + 1, y]) and ((px[x, y] <> x + 1) or (py[x, y] <> y)) then begin
      writeln('BUG');
      halt(0);
    end;
    if (used[x, y - 1]) and ((px[x, y] <> x) or (py[x, y] <> y - 1)) then begin
      writeln('BUG');
      halt(0);
    end;
    if (used[x, y + 1]) and ((px[x, y] <> x) or (py[x, y] <> y + 1)) then begin
      writeln('BUG');
      halt(0);
    end;
  end;
  writeln('OK');
end.