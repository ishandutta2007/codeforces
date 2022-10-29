program task;

{$APPTYPE CONSOLE}

uses
  Math,
  SysUtils;

const maxn = 10000;

var pr, rank : array[1..maxn] of longint;
    num : array[1..maxn] of longint;
    n, i, x, res, cur : longint;

procedure init;
var i : longint;
begin
    for i := 1 to maxn do begin
        pr[i] := i;
        rank[i] := 0;
        num[i] := 0;
    end;
end;

function findset(u : longint) : longint;
begin
    if pr[u] = u then findset := u else begin
        pr[u] := findset(pr[u]);
        findset := pr[u];
    end;
end;

procedure link(x, y : longint);
begin
    if rank[x] >= rank[y] then pr[y] := x else pr[x] := y;
    if rank[x] = rank[y] then inc(rank[x]);
end;

procedure union(x, y : longint);
begin
    link(findset(x), findset(y));
end;

begin
    //init;
    readln(n);
    for i := 1 to n do begin
        readln(x);
        //if x <> -1 then union(i, x);
        pr[i] := x;
    end;
    {for i := 1 to n do
        inc(num[findset(i)]);
    res := 0;
    for i := 1 to n do
        res := max(res, num[i]);}
    res := 0;
    for i := 1 to n do begin
        cur := 1;
        x := pr[i];
        while x <> -1 do begin
            inc(cur);
            x := pr[x];
        end;
        res := max(res, cur);
    end;
    writeln(res);
    halt(0);
end.