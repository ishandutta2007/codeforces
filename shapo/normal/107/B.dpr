program task;

{$APPTYPE CONSOLE}

uses
  Math,
  SysUtils;

var res : extended;
    n, m, h, i, cur, a  : longint;
    s : array[1..10000] of longint;

begin
    cur := 0;
    readln(n, m, h);
    for i := 1 to m do begin
        read(s[i]);
        cur := cur + s[i];
    end;
    readln;
    res := -1;
    dec(cur);
    dec(n);
    if cur >= n then begin
        res:=1;
        a := cur - s[h] + 1;
        if a >= n then begin
            for i := 1 to n do
                res := res * (a - n + i) / (cur - n + i);
            res := 1.0 - res;
        end;
    end;
    writeln(res : 0 : 10);
    halt(0);
end.