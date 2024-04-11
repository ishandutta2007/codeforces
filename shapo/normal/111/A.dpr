program task;

{$APPTYPE CONSOLE}

uses
  Math,
  SysUtils;

var n, y, i : longint;
    x, sum : int64;

begin
    readln(n, x, y);
    sum := (n - 1);
    sum := sum + int64(y - n + 1) * int64(y - n + 1);
    if (sum < x) or (y < n) then writeln(-1) else begin
        for i := 1 to n - 1 do
            writeln(1);
        writeln(y - n + 1);
    end;
    halt(0);
end.