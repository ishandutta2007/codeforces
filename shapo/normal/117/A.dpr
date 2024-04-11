program task;

{$APPTYPE CONSOLE}

uses
  Math,
  SysUtils;

const maxn = 200 * 1000;

var res : array[1..maxn] of longint;
    n, m, i, s, f, t, tt, a, b : longint;

begin
    //assign(input, 'input.txt');
    //assign(output, 'output.txt');
    readln(n, m);
    for i := 1 to n do begin
        readln(s, f, t);
        if s = f then res[i] := t else begin
            b := t mod (2 * m - 2);
            //writeln(b);
            if (b > m - 1) then a := 2 * m - 1 - b else a := b + 1;
            if (b >= m - 1) then b := 1 else b := 0;
            //writeln('i: ', i, ' a: ', a, ' ', b);
            if (s < f) then begin
                if (b = 0) then begin
                    if (a > s) then
                        tt := t + 2 * m + f - a - 2
                    else
                        tt := f - a + t;
                end
                else begin
                    tt := t + a + f - 2;
                end;
            end
            else begin
                if (b = 0) then begin
                    tt := t + 2 * m - a - f;
                end
                else begin
                    if (a < s) then
                        tt := t + 2 * m + a - f - 2
                    else
                        tt := t + a - f;
                end;
            end;
            res[i] := tt;
        end;
    end;
    for i := 1 to n do
        writeln(res[i]);
    halt(0);
end.