program task;

{$APPTYPE CONSOLE}

uses
  Math,
  SysUtils;

var n, m, a, b, pa, pb, la, lb, res : longint;

begin
    readln(n, m, a, b);
    dec(a);
    dec(b);
    pa := a mod m;
    pb := b mod m;
    la := a div m;
    lb := b div m;
    res := 3;
    if la = lb then res := min(res, 1);
    if (lb - la = 1) then begin
        if (pa = 0) and (pb = m - 1) then res := min(res, 1) else res := min(res, 2);
    end;
    if (pa = 0) and (pb = m - 1) then res := min(res, 1);
    if pb = pa - 1 then res := min(res, 2);
    if pb = m - 1 then res := min(res, 2);
    if (a = 0) and (b = n - 1) then res := 1;
    if (pa = 0) and (b = n - 1) then res := 1;
    if (b = n - 1) then res := min(res, 2);
    if (pa = 0) or (pb = m - 1) then res := min(res, 2);
    writeln(res);
    halt(0);
end.