program task;

{$APPTYPE CONSOLE}

uses
  Math,
  SysUtils;

type struct = record
    a : extended;
end;

var n, k, a, i : longint;
    res, a1, b, ver, rr : extended;
    lew : array[1..8] of extended;
    add : array[1..8] of longint;
    cur, now : array[1..8] of struct;

function otv(y : extended; z : longint) : extended;
begin
    if z > (n div 2) then otv := 1 else otv := a1 / (a1 + y);
end;

procedure make_search(x, y : longint; var res : extended);
begin
    if x > n then res := res + ver * otv(b, y)
    else begin
        cur[x].a := now[x].a / 100 + add[x] * 0.1;
        if cur[x].a <> 0 then begin
            ver := ver * cur[x].a;
            make_search(x + 1, y + 1, res);
            ver := ver / cur[x].a;
        end;
        if cur[x].a <> 1 then begin
            ver := ver * (1 - cur[x].a);
            b := b + lew[x];
            make_search(x + 1, y, res);
            b := b - lew[x];
            ver := ver / (1 - cur[x].a);
        end;
    end;
end;

procedure add_k(x, y : longint);
var i : longint;
begin
    if x > n then begin
        ver := 1;
        b := 0;
        rr := 0;
        make_search(1, 0, rr);
        res := max(res, rr);
    end
    else begin
        for i := 0 to y do
            if (100 - now[x].a >= 10 * i)then begin
                add[x] := i;
                add_k(x + 1, y - i);
            end;
    end;
end;

begin
    //assign(input, 'input.txt');
    //assign(output, 'output.txt');
    readln(n, k, a);
    a1 := a;
    res := 0;
    for i := 1 to n do
        readln(lew[i], now[i].a);
    add_k(1, k);
    writeln(res : 0 : 10);
end.