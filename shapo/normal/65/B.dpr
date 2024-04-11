program b;

{$APPTYPE CONSOLE}

uses
  Math,
  SysUtils;

var n, i, j, k, cur : integer;
    a : array[1..1000, 1..4] of integer;
    p : array[1..1000] of integer;
    vzm : array[1..1000, 0..40] of integer;
    sm : array[1..1000, 1000..9999] of boolean;
    res : array[1..1000] of integer;

begin
    readln(n);
    fillchar(sm, sizeof(sm), false);
    for i := 1 to n do begin
        readln(cur);
        p[i] := cur;
        a[i, 1] := cur div 1000;
        a[i, 2] := (cur mod 1000) div 100;
        a[i, 3] := (cur mod 100) div 10;
        a[i, 4] := cur mod 10;
    end;
    for i := 1 to n do begin
        vzm[i, 0] := 0;
        for k := 1 to 2 do begin
            inc(vzm[i, 0]);
            vzm[i, vzm[i, 0]] := k * 1000 + a[i, 2] * 100 + a[i, 3] * 10 + a[i, 4];
        end;
        for k := 0 to 9 do begin
            inc(vzm[i, 0]);
            vzm[i, vzm[i, 0]] := a[i, 1] * 1000 + k * 100 + a[i, 3] * 10 + a[i, 4];
            inc(vzm[i, 0]);
            vzm[i, vzm[i, 0]] := a[i, 1] * 1000 + a[i, 2] * 100 + k * 10 + a[i, 4];
            inc(vzm[i, 0]);
            vzm[i, vzm[i, 0]] := a[i, 1] * 1000 + a[i, 2] * 100 + a[i, 3] * 10 + k;
        end;
    end;
    for j := 1 to vzm[1, 0] do
        sm[1, vzm[1, j]] := true;
    for i := 2 to n do
        for j := 1 to vzm[i, 0] do
            for k := 1 to vzm[i - 1, 0] do begin
                sm[i, vzm[i, j]] :=
                sm[i, vzm[i, j]] or ((vzm[i, j] >= vzm[i - 1, k]) and sm[i - 1, vzm[i - 1, k]]);
            end;
    cur := 0;
    for i := 1000 to 2011 do
        if sm[n, i] then cur := 1;
    if cur = 0 then begin
        writeln('No solution');
        halt(0);
    end;
    cur := 2011;
    for i := n downto 1 do begin
        while (not sm[i, cur]) do dec(cur);
        res[i] := cur;
    end;
    for i := 1 to n do
        writeln(res[i]);
end.