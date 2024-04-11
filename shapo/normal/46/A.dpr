program A;

{$APPTYPE CONSOLE}

uses
  Math,
  SysUtils;

var n, i, cur : integer;

begin
    readln(n);
    cur := 1;
    for i := 1 to n - 1 do begin
        cur := (cur + i) mod n;
        if cur = 0 then cur := n;
        write(cur, ' ');
    end;
end.