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
  a, b, c, d, e, f : integer;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(a, b, c, d, e, f);
  if d = 0 then begin
    writeln('Hermione');
    halt(0);
  end;
  if c = 0 then begin
    writeln('Ron');
    halt(0);
  end;
  if b = 0 then begin
    writeln('Hermione');
    halt(0);
  end;
  if a = 0 then begin
    writeln('Ron');
    halt(0);
  end;
  if f = 0 then begin
    writeln('Hermione');
    halt(0);
  end;
  if e = 0 then begin
    writeln('Ron');
    halt(0);
  end;
  if b * d * f > a * c * e then begin
    writeln('Ron');
    halt(0);
  end;
  writeln('Hermione');
end.