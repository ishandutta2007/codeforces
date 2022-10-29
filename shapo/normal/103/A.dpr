program task;

{$APPTYPE CONSOLE}

uses
  Math,
  SysUtils;

var n, i : longint;
    a : array[1..200] of int64;
    cur, res : int64;

begin
    res := 0;
    readln(n);
    for i := 1 to n do
        read(a[i]);
    for i := 1 to n do begin
        cur := a[i] * int64(i) - i + 1;
        res := res + cur;
    end;
    readln;
    writeln(res);
    halt(0);
end.