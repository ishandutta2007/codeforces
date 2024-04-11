program task;

{$APPTYPE CONSOLE}

uses
  Math,
  SysUtils;

var n, i, j, y, x : longint;
    last, cur : array[1..100000] of longint;

begin
    fillchar(last, sizeof(last), 0);
    readln(n);
    for i := 1 to n do begin
        readln(x, y);
        j := 1;
        cur[i] := 0;
        while (j * j <= x) do begin
            if (x mod j = 0) then begin
                if (y = 0) or (last[j] < i - y) then inc(cur[i]);
                if (j <> x div j) and ((y = 0) or (last[x div j] < i - y)) then inc(cur[i]);
                last[j] := i;
                last[x div j] := i;  
            end;
            inc(j);
        end;
    end;
    for i := 1 to n do
        writeln(cur[i]);
    halt(0);
end.