program D;

{$APPTYPE CONSOLE}

uses
  Math,
  SysUtils;

type car = record
    x, y, z : integer;
end;

var l, f, b, a, cur, n, i : integer;
    sm : array[0..200] of car;
    res : array[0..100] of car;

procedure push(u, v : integer);
var i, j : integer;
begin
    i := 1;
    while (i < sm[0].x) and (sm[i + 1].x - sm[i].y < f + b + u) do inc(i);
    if i = sm[0].x then res[v].y := -1 else begin
        res[v].x := i + 1;
        res[v].y := sm[i].y + b;
        inc(sm[0].x);
        for j := sm[0].x downto i + 2 do begin
            sm[j] := sm[j - 1];
            res[sm[j].z].x := j;
        end;
        sm[i + 1].x := sm[i].y + b;
        sm[i + 1].y := sm[i + 1].x + u;
        sm[i + 1].z := v;
    end;
end;

procedure pop(u, v : integer);
var i : integer;
begin
    res[v].x := -2;
    sm[res[u].x].x := 0;
    for i := res[u].x + 1 to sm[0].x do begin
        sm[i - 1] := sm[i];
        res[sm[i - 1].z].x := i - 1;
    end;
    dec(sm[0].x);
end;

begin
    readln(l, b, f);
    readln(n);
    sm[0].x := 2;
    sm[1].x := -b;
    sm[1].y := -b;
    sm[2].x := l + f;
    sm[2].y := l + f;
    for i := 1 to n do begin
        readln(a, cur);
        if a = 1 then push(cur, i) else pop(cur, i);
    end;
    for i := 1 to n do begin
        if res[i].x <> -2 then writeln(res[i].y);
    end;
end.