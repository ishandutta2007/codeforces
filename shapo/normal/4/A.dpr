program Project3;

{$APPTYPE CONSOLE}

uses
  Math, SysUtils;

var w : integer;

begin
    readln(w);
    if (w mod 2 = 0) and (w > 2) then writeln('YES') else writeln('NO');
end.