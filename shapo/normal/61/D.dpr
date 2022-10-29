program d;

{$APPTYPE CONSOLE}

uses
  Math,
  SysUtils;

type edge = record
    x, y : integer;
    w : int64;
end;

type sp = record
    id : integer;
    w : int64;
    next : integer;
end;

var n, i, mn : integer;
    res, mx : int64;
    a : array[1..100000] of edge;
    num, last : array[1..100000] of integer;
    used : array[1..100000] of boolean;
    pos : array[1..500000] of sp;

function DFS(u : integer; var p : int64) : int64;
var i, v : integer;
    cur, l, res : int64;
begin
    cur := 0;
    res := 0;
    used[u] := true;
    i := num[u];
    while (i <> 0) do begin
        v := pos[i].id;
        if not used[v] then begin
            res := res + 2 * pos[i].w + DFS(v, l);
            cur := max(cur, pos[i].w + l);
        end;
        i := pos[i].next;
    end;
    p := cur;
    DFS := res;
end;

begin
    readln(n);
    mn := 0;
    mx := 0;
    fillchar(num, sizeof(num), 0);
    fillchar(pos, sizeof(pos), 0);
    fillchar(used, sizeof(used), false);
    for i := 1 to n - 1 do begin
        readln(a[i].x, a[i].y, a[i].w);
        inc(mn);
        if num[a[i].x] = 0 then begin
            num[a[i].x] := mn;
            pos[mn].id := a[i].y;
            pos[mn].w := a[i].w;
            last[a[i].x] := mn;
        end
        else begin
            pos[last[a[i].x]].next := mn;
            pos[mn].id := a[i].y;
            pos[mn].w := a[i].w;
            last[a[i].x] := mn;
        end;
        inc(mn);
        if num[a[i].y] = 0 then begin
            num[a[i].y] := mn;
            pos[mn].id := a[i].x;
            pos[mn].w := a[i].w;
            last[a[i].y] := mn;
        end
        else begin
            pos[last[a[i].y]].next := mn;
            pos[mn].id := a[i].x;
            pos[mn].w := a[i].w;
            last[a[i].y] := mn;
        end;
    end;
    res := DFS(1, mx) - mx;
    writeln(res);
end.