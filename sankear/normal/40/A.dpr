program solution;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Math;

var
  x, y, r, i : integer;

function bad(r : integer) : boolean;
begin
  result := x * x + y * y = r * r;
end;

function good(r : integer) : boolean;
begin
  result := x * x + y * y < r * r;
end;

begin
  //reset(input, 'input.txt');
  //rewrite(output, 'output.txt');
  read(x, y);
  if (x = 0) or (y = 0) then begin
    writeln('black');
    halt(0);
  end;
  for i := 1 to 2000 do
    if bad(i) then begin
      writeln('black');
      halt(0);
    end;
  for i := 1 to 2000 do
    if good(i) then begin
      r := i;
      break;
    end;
  if r mod 2 = 0 then begin
    if (x > 0) and (y > 0) then begin
      writeln('white');
      halt(0);
    end;
    if (x > 0) and (y < 0) then begin
      writeln('black');
      halt(0);
    end;
    if (x < 0) and (y > 0) then begin
      writeln('black');
      halt(0);
    end;
    if (x < 0) and (y < 0) then begin
      writeln('white');
      halt(0);
    end;
  end;
  if (x > 0) and (y > 0) then begin
    writeln('black');
    halt(0);
  end;
  if (x > 0) and (y < 0) then begin
    writeln('white');
    halt(0);
  end;
  if (x < 0) and (y > 0) then begin
    writeln('white');
    halt(0);
  end;
  if (x < 0) and (y < 0) then begin
    writeln('black');
    halt(0);
  end;
end.