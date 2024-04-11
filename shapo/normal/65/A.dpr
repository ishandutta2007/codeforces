program a;

{$APPTYPE CONSOLE}

uses
  Math,
  SysUtils;

var aa, b, c, d, e, f : integer;

begin
    readln(aa, b, c, d, e, f);
    if (c = 0) and (d <> 0) then begin
        writeln('Ron');
        halt(0);
    end;
    if d = 0 then begin
        writeln('Hermione');
        halt(0);
    end;
    if (aa = 0) and (b <> 0) then begin
        writeln('Ron');
        halt(0);
    end;
    if (b = 0) then begin
        writeln('Hermione');
        halt(0);
    end;
    if (f = 0) then begin
        writeln('Hermione');
        halt(0);
    end;
    if (e = 0) and (f <> 0) then begin
        writeln('Ron');
        halt(0);
    end;
    if (aa * c * e < b * d * f) then writeln('Ron') else writeln('Hermione');
end.