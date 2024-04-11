program a;

{$APPTYPE CONSOLE}

uses
  Math,
  SysUtils;

var al,ar, bl, br : integer;

function ok(x, y : integer): boolean;
begin
    if (y >= x - 1) and (2* (x + 1) >= y) then ok := true else ok := false;
end;

begin
    readln(al, ar);
    readln(bl, br);
    if ok(al, br) or ok(ar, bl) then writeln('YES') else writeln('NO');
end.