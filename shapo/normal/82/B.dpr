program snm;

{$APPTYPE CONSOLE}

uses
  Math,
  SysUtils;

const maxn = 25000;

type mass = array[1..250] of integer;

type list = record
    n : integer;
    a : mass;
end;

var n, i, j, maxa, num, k : integer;
    sm : array[1..maxn] of list;
    sp : array[1..200, 0..250] of integer;
    res : array[1..200] of list;
    used : array[1..200] of boolean;

begin
    fillchar(sp, sizeof(sp), 0);
    readln(n);
    fillchar(used, sizeof(used), false);
    for i := 1 to (n * (n - 1)) div 2 do begin
        read(sm[i].n);
        for j := 1 to sm[i].n do begin
            read(k);
            inc(sp[k, 0]);
            sp[k, sp[k, 0]] := i;
        end;
        readln;
    end;

    num := 0;
    maxa := 200;
    if n > 2 then begin
        for i := 1 to maxa do
            if not used[i] then begin
                used[i] := true;
                if sp[i, 0] <> 0 then begin
                    inc(num);
                    res[num].n := 1;
                    res[num].a[1] := i;
                    for j := i to maxa do
                        if (not used[j]) and (sp[j, 0] <> 0) and (sp[j, 0] = sp[i, 0]) then begin
                            k := 1;
                            while (k <= sp[j, 0]) and (sp[i, k] = sp[j, k]) do inc(k);
                            if k > sp[j, 0] then begin
                                used[j] := true;
                                inc(res[num].n);
                                res[num].a[res[num].n] := j;
                            end;
                        end;
                end;
            end;
        end
    else begin
        num := 2;
        res[1].n := 1;
        res[2].n := 0;
        i := 1;
        while sp[i, 0] = 0 do inc(i);
        res[1].a[1] := i;
        inc(i);
        while (i <= 200) do begin
            if sp[i, 0] > 0 then begin
                inc(res[2].n);
                res[2].a[res[2].n] := i;
            end;
            inc(i);
        end;
    end;

    for i := 1 to n do begin
        write(res[i].n);
        for j := 1 to res[i].n do
            write(' ', res[i].a[j]);
        writeln;
    end;
    halt(0);
end.