program task;

{$APPTYPE CONSOLE}

uses
  Math,
  SysUtils;

const maxk = 1 shl 12;
      maxp = maxk - 1;

type sp = record
    x : longint;
    res : int64;
end;

type ver = record
    num : longint;
    a : array[1..2000] of sp;
end;

type sp1 = record
    x, res : int64;
end;

var n, m, i, x, y, cur, j : longint;
    len : array[1..2000, 1..2000] of int64;
    used : array[1..2000] of boolean;
    res : array[1..2000] of int64;
    tree : array[1..maxk + maxp] of sp;
    sm : array[1..2000] of ver;
    pp, a, b, c : int64;
    cost : array[1..2000] of sp1;

function min_tree(a, b : sp) : sp;
begin
    if (a.res < b.res) then min_tree := a else min_tree := b;
end;

procedure init;
var i : longint;
begin
    for i := maxk to maxp + maxk do begin
        tree[i].x := i - maxp;
        tree[i].res := 1000 * 1000 * 1000;
        tree[i].res := tree[i].res * int64(2000);
    end;
    for i := maxp downto 1 do
        tree[i] := min_tree(tree[2 * i], tree[2 * i + 1]);
end;

procedure dijkstra(u : longint);
var j, cur, p1, p2, pp1 : longint;
begin
    init;
    //writeln('dijkstra ', u);
    for j := 1 to n do
        len[u, j] := pp;
    tree[u + maxp].res := 0;
    len[u, u] := 0;
    p1 := (u + maxp) div 2;
    while p1 <> 0 do begin
        tree[p1] := min_tree(tree[p1 * 2], tree[p1 * 2 + 1]);
        p1 := p1 div 2;
    end;
    cur := tree[1].x;
    while (tree[cur + maxp].res <> pp) do begin
        len[u, cur] := tree[cur + maxp].res;
        tree[cur + maxp].res := pp;
        pp1 := (cur + maxp) div 2;
        while pp1 <> 0 do begin
            tree[pp1] := min_tree(tree[pp1 * 2], tree[pp1 * 2 + 1]);
            pp1 := pp1 div 2;
            end;
        for j := 1 to sm[cur].num do begin
            p1 := sm[cur].a[j].x;
            p2 := sm[cur].a[j].res;
            if (len[u, p1] = tree[p1 + maxp].res) and
            (len[u, p1] > len[u, cur] + p2)
            then begin
                len[u, p1] := len[u, cur] + p2;
                tree[p1 + maxp].res := len[u, p1];
                pp1 := (p1 + maxp) div 2;
                while pp1 <> 0 do begin
                    tree[pp1] := min_tree(tree[pp1 * 2], tree[pp1 * 2 + 1]);
                    pp1 := pp1 div 2;
                end;
            end;
        end;
        cur := tree[1].x;
    end;
    {for i := 1 to n do
        write(len[u, i], ' ');
    writeln;}
end;

begin
    //assign(input, 'input.txt');
    readln(n, m);
    readln(x, y);
    init;
    for i := 1 to n do begin
        res[i] := 1000 * 1000 * 1000;
        res[i] := res[i] * int64(2000);
        sm[i].num := 0;
    end;
    pp := res[1];
    for i := 1 to m do begin
        readln(a, b, c);
        inc(sm[a].num);
        sm[a].a[sm[a].num].x := b;
        sm[a].a[sm[a].num].res := c;
        inc(sm[b].num);
        sm[b].a[sm[b].num].x := a;
        sm[b].a[sm[b].num].res := c;
    end;
    for i := 1 to n do
        readln(cost[i].x, cost[i].res);
    for i := 1 to n do
        dijkstra(i);
    res[x] := 0;
    fillchar(used, sizeof(used), false);
    cur := x;
    while not used[cur] and (res[cur] <> pp) do begin
//        writeln(cur, ' ', res[cur]);
        used[cur] := true;
        for j := 1 to n do begin
            if not used[j] and (len[cur, j] <= cost[cur].x) then begin
                res[j] := min(res[j], res[cur] + cost[cur].res);
            end;
        end;
        cur := 1;
        for j := 1 to n do begin
            if not used[j] and (used[cur] or (res[cur] > res[j]))
            then cur := j;
        end;
    end;
{    for i := 1 to n do
        writeln(i, ' ', res[i]);}
    if res[y] = pp then writeln(-1) else writeln(res[y]);
    halt(0);
end.