program E;

{$APPTYPE CONSOLE}

uses
  Math,
  SysUtils;

var n, m, i, j, cur : integer;
    res : int64;
    a : array[1..1500, 1..1500] of int64;
    sm : array[1..1500, 0..1500] of int64;
    incr : array[1..1500, 0..1500] of int64;

procedure men(u : integer);
var i : integer;
    max1 : int64;
begin
    max1 := sm[u - 1, m];
    sm[u, m] := -22500000001;
    for i := m - 1 downto 0 do begin
        sm[u, i] := max1 + incr[u, i];
        max1 := max(max1, sm[u - 1, i]);
    end;
end;

procedure bol(u : integer);
var i : integer;
    max1 : int64;
begin
    max1 := -22500000001;
    sm[u, 0] := -22500000001;
    for i := 1 to m do begin
        sm[u, i] := max1 + incr[u, i];
        max1 := max(max1, sm[u - 1, i]);
    end;
end;

begin
    readln(n, m);
    fillchar(incr, sizeof(incr), 0);
    for i := 1 to n do begin
        for j := 1 to m do begin
            read(cur);
            a[i, j] := cur;
        end;
        readln;
    end;
    sm[1, 0] := 0;
    for i := 1 to n do
        for j := 1 to m do
            incr[i, j] := incr[i, j - 1] + a[i, j];
    for i := 1 to m do
        sm[1, i] := incr[1, i];
    for i := 2 to n do
        if (i mod 2 = 0) then men(i) else bol(i);
    res := -22500000001;
    for i := 1 to m do
        res := max(res, sm[n, i]);
    writeln(res);
end.