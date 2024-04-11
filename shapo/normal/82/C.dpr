program station;

{$APPTYPE CONSOLE}

uses
  Math,
  SysUtils;

type list = record
    x, id : integer;
end;

type ver = record
    y : integer;
    next : integer;
end;

type typ = record
    pr, put : integer;
end;

type ver1 = record
    x, y, c : integer;
end;

const mn = 5000;

var n, i, num, x, y, z, j, mini : integer;
    a : array[1..mn] of list;
    par : array[1..mn] of typ;
    cur : array[1..mn] of ver1;
    sm : array[1..mn, 0..mn] of integer;
    sm1 : array[1..3 * mn] of ver;
    res, beg, en : array[1..mn] of integer;
    used : array[1..mn] of boolean;
    maxa : integer;

procedure add(u, v : integer);
begin
    inc(num);
    sm1[num].y := v;
    if beg[u] = 0 then beg[u] := num;
    sm1[num].next := 0;
    if en[u] <> 0 then sm1[en[u]].next := num;
    en[u] := num;
end;

procedure DFS(u, pra, ptu : integer);
var i, p : integer;
begin
    used[u] := true;
    par[u].pr := pra;
    par[u].put := ptu;
    i := beg[u];
    while i <> 0 do begin
        p := cur[sm1[i].y].x;
        if p = u then p := cur[sm1[i].y].y;
        if not used[p] then DFS(p, u, sm1[i].y);
        i := sm1[i].next;
    end;
end;

procedure push(u : integer; var v : integer);
var i, cur : integer;
begin
    i := u;
    cur := 0;
    while (i <> 1) do begin
        while sm[par[i].put, cur] = 0 do inc(cur);
        dec(sm[par[i].put, cur]);
        inc(cur);
        i := par[i].pr;
    end;
    v := cur;
end;

begin
    fillchar(beg, sizeof(beg), 0);
    fillchar(en, sizeof(en), 0);
    fillchar(used, sizeof(used), false);
    readln(n);
    num := 0;
    maxa := 0;
    for i := 1 to n do begin
        read(a[i].x);
        a[i].id := i;
        maxa := max(maxa, a[i].x);
    end;
    res[1] := 0;
    for i := 1 to n - 1 do begin
        readln(x, y, z);
        cur[i].x := x;
        cur[i].y := y;
        cur[i].c := z;
        add(x, i);
        add(y, i);
        for j := 0 to n - 1 do
            sm[i, j] := z;
    end;
    DFS(1, 0, 0);
    for i := 1 to n do begin
        mini := 1;
        for j := 2 to n do
            if a[j].x < a[mini].x then mini := j;
        a[mini].x := maxa + 1;
        push(mini, res[mini]);
    end;
    for i := 1 to n do
        write(res[i], ' ');
    halt(0);
end.