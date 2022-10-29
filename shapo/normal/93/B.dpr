program task;

{$APPTYPE CONSOLE}

uses
  Math,
  SysUtils;

const eps = 1e-9;

type totype = record
    sm : array[1..100, 1..2] of extended;
    num : longint;
end;

var n, w, m : longint;
    num : extended;
    cur, milk : array[1..100] of extended;
    ind : array[1..100] of longint;
    res : array[1..100] of totype;
    i, j, max1 : longint;

procedure add(u, b : longint; v : extended);
begin
    inc(ind[b]);
    inc(res[u].num);
    res[u].sm[res[u].num, 1] := b;
    res[u].sm[res[u].num, 2] := v;
end;

begin
    readln(n, w, m);
    num := (n * w) / m;
    if (3 * n < 2 * m) and (m <> 2 * n) then writeln('NO') else begin
        for i := 1 to m do begin
            cur[i] := num;
            res[i].num := 0;
        end;
        for i := 1 to n do begin
            milk[i] := w;
            ind[i] := 0;
        end;
        i := 1;
        j := 1;
        while (i <= n) and (j <= m) do begin
            if (milk[i] - cur[j]) > eps then begin
                milk[i] := milk[i] - cur[j];
                add(j, i, cur[j]);
                inc(j);
            end
            else begin
                if abs(milk[i] - cur[j]) > eps then begin
                    cur[j] := cur[j] - milk[i];
                    add(j, i, milk[i]);
                    inc(i);
                end
                else begin
                    add(j, i, cur[j]);
                    inc(i);
                    inc(j);
                end;
            end;
        end;
        max1 := 0;
        for i := 1 to n do
            max1 := max(max1, ind[i]);
        if max1 >= 3 then writeln('NO') else begin
            writeln('YES');
            for i := 1 to m do begin
                for j := 1 to res[i].num do
                    write(res[i].sm[j, 1] : 0 : 0, ' ', res[i].sm[j, 2] : 0 : 10, ' ');
            writeln;
            end;
        end;
    end;
    halt(0);
end.