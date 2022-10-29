program task;

{$APPTYPE CONSOLE}

uses
  Math,
  SysUtils;

var n, m, i : longint;
    res : array[1..40, 1..40] of longint;

begin
    readln(n, m);
    if n > m then begin
        i := n;
        n := m;
        m := i;
    end;
    for i := 1 to 40 do
        res[1, i] := (i + 2) div 3;
    for i := 2 to 20 do
        res[2, i] := (i + 2) div 2;
    res[3, 3] := 3; res[3, 4] := 4; res[3, 5] := 4; res[3, 6] := 5; res[3, 7] := 6; res[3, 8] := 7;
    res[3, 9] := 7; res[3, 10] := 8; res[3, 11] := 9; res[3, 12] := 10; res[3, 13] := 10;
    res[4, 4] := 4; res[4, 5] := 6; res[4, 6] := 7; res[4, 7] := 7; res[4, 8] := 8;
    res[4, 9] := 10; res[4, 10] := 10;
    res[5, 5] := 7; res[5, 6] := 8; res[5, 7] := 9; res[5, 8] := 11;
    res[6, 6] := 10;
    writeln(n * m - res[n, m]);
    halt(0);
end.