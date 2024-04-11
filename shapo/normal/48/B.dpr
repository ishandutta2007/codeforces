program Project2;

{$APPTYPE CONSOLE}

uses
  Math, SysUtils;

var n, m, a, b, i, j : integer;
    sm, res : array[0..50, 0..50] of integer;

function obr(a, b, c, d : integer) : integer;
begin
    obr := res[a, b] - res[a - c, b] - res[a, b - d] + res[a - c, b - d];
end;

function rec(a, b, c, d : integer): integer;
var i, j, mn : integer;
begin
    mn := 2501;
    if (c <= a) and (d <= b) then begin
        for i := a downto c do
            for j := b downto d do
             mn := min(mn, obr(i, j, c, d));
    end;
    rec := mn;
end;

begin
    readln(n, m);
    fillchar(res, sizeof(res), 0);
    for i := 1 to n do begin
        for j := 1 to m do begin
            read(sm[i, j]);
            res[i, j] := res[i - 1, j] + res[i, j - 1] - res[i - 1, j - 1] + sm[i, j];
        end;
        readln;
    end;
    readln(a, b);
    writeln(min(rec(n, m, a, b), rec(n, m, b, a)));
end.