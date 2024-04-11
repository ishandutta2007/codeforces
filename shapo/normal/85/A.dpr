program a;

{$APPTYPE CONSOLE}

uses
  Math,
  SysUtils;

var n, i, j : integer;
    res : array[1..4, 1..100] of integer;
    cur : integer;

begin
    readln(n);
    cur := 1;
    if n mod 2 = 0 then begin
        for i := 1 to n div 2 do begin
            res[1, 2 * i - 1] := cur;
            res[1, 2 * i] := cur;
            cur := 3 - cur;
            res[2, 2 * i - 1] := cur;
            res[2, 2 * i] := cur;
        end;
        res[3, 1] := 9;
        res[4, 1] := 9;
        cur := 5;
        for i := 1 to (n div 2) - 1 do begin
            res[3, 2 * i] := cur;
            res[3, 2 * i + 1] := cur;
            cur := 9 - cur;
            res[4, 2 * i] := cur;
            res[4, 2 * i + 1] := cur;
        end;
        res[3, n] := 10;
        res[4, n] := 10;
    end
    else begin
        cur := 1;
        for i := 1 to (n - 1) div 2 do begin
            res[1, 2 * i - 1] := cur;
            res[1, 2 * i] := cur;
            cur := 3 - cur;
            res[2, 2 * i - 1] := cur;
            res[2, 2 * i] := cur;
        end;
        res[1, n] := 9;
        res[2, n] := 9;
        res[3, 1] := 10;
        res[4, 1] := 10;
        cur := 4;
        for i := 1 to (n - 1) div 2 do begin
            res[3, 2 * i] := cur;
            res[3, 2 * i + 1] := cur;
            cur := 9 - cur;
            res[4, 2 * i] := cur;
            res[4, 2 * i + 1] := cur;
        end;
    end;
    for i := 1 to 4 do begin
        for j := 1 to n do
            write(chr(res[i, j] + ord('a')));
        writeln;
    end;
    halt(0);
end.