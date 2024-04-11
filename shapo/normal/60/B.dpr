program b;

{$APPTYPE CONSOLE}

uses
  Math,
  SysUtils;

type tar = record
    z, x, y : integer;
end;

var n, m, k, x, y, i, j, l, beg, en, res : integer;
    sm, a : array[0..11, 0..11, 0..11] of integer;
    c : char;
    q : array[1..1000] of tar;

procedure BFS(u : integer);
var cur : tar;
begin
    cur := q[u];
    dec(cur.z);
    if (a[cur.z, cur.x, cur.y] = 1) and (sm[cur.z, cur.x, cur.y] = 0) then begin
        sm[cur.z, cur.x, cur.y] := 1;
        inc(en);
        q[en] := cur;
    end;
    cur := q[u];
    inc(cur.z);
    if (a[cur.z, cur.x, cur.y] = 1) and (sm[cur.z, cur.x, cur.y] = 0) then begin
        sm[cur.z, cur.x, cur.y] := 1;
        inc(en);
        q[en] := cur;
    end;
    cur := q[u];
    dec(cur.x);
    if (a[cur.z, cur.x, cur.y] = 1) and (sm[cur.z, cur.x, cur.y] = 0) then begin
        sm[cur.z, cur.x, cur.y] := 1;
        inc(en);
        q[en] := cur;
    end;
    cur := q[u];
    inc(cur.x);
    if (a[cur.z, cur.x, cur.y] = 1) and (sm[cur.z, cur.x, cur.y] = 0) then begin
        sm[cur.z, cur.x, cur.y] := 1;
        inc(en);
        q[en] := cur;
    end;
    cur := q[u];
    dec(cur.y);
    if (a[cur.z, cur.x, cur.y] = 1) and (sm[cur.z, cur.x, cur.y] = 0) then begin
        sm[cur.z, cur.x, cur.y] := 1;
        inc(en);
        q[en] := cur;
    end;
    cur := q[u];
    inc(cur.y);
    if (a[cur.z, cur.x, cur.y] = 1) and (sm[cur.z, cur.x, cur.y] = 0) then begin
        sm[cur.z, cur.x, cur.y] := 1;
        inc(en);
        q[en] := cur;
    end;
end;

begin
    fillchar(sm, sizeof(sm), 0);
    readln(k, n, m);
    fillchar(a, sizeof(a), -1);
    for l := 1 to k do begin
        readln;
        for i := 1 to n do begin
            for j := 1 to m do begin
                read(c);
                if c = '.' then a[l, i, j] := 1 else a[l, i, j] := -1;
            end;
            readln;
        end;
    end;
    readln(x, y);
    sm[1, x, y] := 1;
    beg := 1;
    en := 1;
    q[en].z := 1;
    q[en].x := x;
    q[en].y := y;
    while (beg <= en) do begin
        BFS(beg);
        inc(beg);
    end;
    res := 0;
    for l := 1 to k do
        for i := 1 to n do
            for j := 1 to m do
                res := res + sm[l, i, j];
    writeln(res);
end.