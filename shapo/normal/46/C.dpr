program C;

{$APPTYPE CONSOLE}

uses
  Math,
  SysUtils;

var n, i, h, t, min1, cur : integer;
    s : string;
    a : array[1..2000] of integer;

function can(u : integer) : integer;
var res, n1, cur : integer;
begin
    n1 := t;
    cur := u - 1;
    res := 0;
    while (n1 <> 0) do begin
        cur := (cur + 1) mod n;
        if cur = 0 then cur := n;
        dec(n1);
        if a[cur] <> 2 then inc(res);
    end;
    can := res;
end;

begin
    readln(n);
    readln(s);
    h := 0;
    t := 0;
    for i := 1 to n do begin
        if s[i] = 'H' then begin
            inc(h);
            a[i] := 1;
        end
        else begin
            inc(t);
            a[i] := 2;
        end;
    end;
    min1 := n * n;
    for i := 1 to n do begin
        cur := can(i);
        if cur < min1 then min1 := cur;
    end;
    writeln(min1);
end.