program solution;

{$APPTYPE CONSOLE}

uses
  Math,
  SysUtils;

var n, i, res, mn : longint;
    m, k, n1 : int64;
    sm : array[1..100000] of longint;

begin
    readln(n, m, k);
    n1 := n;
    mn := 1000 * 1000;
    for i := 1 to n do begin
        read(sm[i]);
        if i mod 2 = 1 then mn := min(sm[i], mn);
    end;
    readln;
    res := 0;
    if (n1 mod 2 = 1) and ((n1 + 1) div 2 <= m) then
        res := min(mn, (m div ((n1 + 1) div 2)) * k);
    writeln(res{, ' ', mn});
    halt(0);
end.