program task;

{$APPTYPE CONSOLE}

uses
  Math,
  SysUtils;

const maxn = 2000;

type edge = record
    b, d : longint;
end;

type mass = record
    n : longint;
    a : array[1..maxn] of edge;
end;

type reul = record
    a, b, d : longint;
end;

var n, i, x, y, z, p : longint;
    outt, inn : array[1..maxn] of longint;
    sm : array[1..maxn] of mass;
    num : longint;
    res : array[1..maxn] of reul;

procedure add(x, y, z : longint);
begin
    inc(sm[x].n);
    sm[x].a[sm[x].n].b := y;
    sm[x].a[sm[x].n].d := z;
    inc(outt[y]);
    inc(inn[x]);
end;

procedure DFS(x, v : longint);
var i : longint;
begin
    if sm[x].n = 0 then begin
        res[num].b := x;
        res[num].d := v;
    end;
    for i := 1 to sm[x].n do
        DFS(sm[x].a[i].b, min(v, sm[x].a[i].d));
end;

begin
    readln(n, p);
    num := 0;
    for i := 1 to n do begin
        sm[i].n := 0;
        outt[i] := 0;
        inn[i] := 0;
    end;
    for i := 1 to p do begin
        readln(x, y, z);
        add(x, y, z);
    end;
    for i := 1 to n do
        if (outt[i] = 0) and (inn[i] <> 0) then begin
            inc(num);
            res[num].a := i;
            DFS(i, 1000010);
        end;
    writeln(num);
    for i := 1 to num do
        writeln(res[i].a, ' ', res[i].b, ' ', res[i].d);
    halt(0);
end.