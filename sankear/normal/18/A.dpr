program solution;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Math;

var
  i : integer;
  x, y : array[1..3] of integer;
  dx, dy : array[1..4] of integer;

function triangle(x1, y1, x2, y2, x3, y3 : integer) : boolean;
begin
  result := abs((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1)) > 0;
end;

function check(x1, y1, x2, y2, x3, y3 : integer) : boolean;
begin
  result := ((x2 - x1) * (x3 - x1) + (y2 - y1) * (y3 - y1) = 0) or ((x1 - x2) * (x3 - x2) + (y1 - y2) * (y3 - y2) = 0) or ((x1 - x3) * (x2 - x3) + (y1 - y3) * (y2 - y3) = 0);
end;

begin
  //reset(input, 'input.txt');
  //rewrite(output, 'output.txt');
  for i := 1 to 3 do
    read(x[i], y[i]);
  if check(x[1], y[1], x[2], y[2], x[3], y[3]) then begin
    write('RIGHT');
    halt(0);
  end;
  dx[1] := 0;
  dy[1] := 1;
  dx[2] := 1;
  dy[2] := 0;
  dx[3] := 0;
  dy[3] := -1;
  dx[4] := -1;
  dy[4] := 0;
  for i := 1 to 4 do
    if (triangle(x[1] + dx[i], y[1] + dy[i], x[2], y[2], x[3], y[3])) and (check(x[1] + dx[i], y[1] + dy[i], x[2], y[2], x[3], y[3])) then begin
      write('ALMOST');
      halt(0);
    end;
  for i := 1 to 4 do
    if (triangle(x[1], y[1], x[2], y[2], x[3] + dx[i], y[3] + dy[i])) and (check(x[1], y[1], x[2], y[2], x[3] + dx[i], y[3] + dy[i])) then begin
      write('ALMOST');
      halt(0);
    end;
  for i := 1 to 4 do
    if (triangle(x[1], y[1], x[2] + dx[i], y[2] + dy[i], x[3], y[3])) and (check(x[1], y[1], x[2] + dx[i], y[2] + dy[i], x[3], y[3])) then begin
      write('ALMOST');
      halt(0);
    end;
  write('NEITHER');
end.