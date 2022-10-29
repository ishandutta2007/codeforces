program task;

{$APPTYPE CONSOLE}

uses
  Math,
  SysUtils;

const pp = 1000 * 1000 * 1000 + 9;

type tr = record
    pr, rank : longint;
end;

var n, m, i, a, b : longint;
    res : array[0..200000] of int64;
    snm : array[1..200000] of tr;

function findset(u : longint) : longint;
var res : longint;
begin
    if snm[u].pr = u then res := u else
        res := findset(snm[u].pr);
    snm[u].pr := res;
    findset := res;
end;

procedure link(x, y : longint);
begin
    if snm[x].rank >= snm[y].rank then snm[y].pr := x else snm[x].pr := y;
    if snm[x].rank >= snm[y].rank then inc(snm[x].rank);
end;

procedure union(x, y : longint);
begin
    link(findset(x), findset(y));
end;

begin
    //assign(input, 'input.txt');
    //assign(output, 'output.txt');
    readln(n, m);
    for i := 1 to n do begin
        snm[i].pr := i;
        snm[i].rank := 0;
    end;
    res[0] := 1;
    for i := 1 to m do begin
        readln(a, b);
        res[i] := res[i - 1];
        if findset(a) <> findset(b) then union(a, b) else res[i] := (res[i - 1] * 2) mod pp;
        res[i - 1] := (res[i - 1] + pp - 1) mod pp;
    end;
    res[m] := (res[m] + pp - 1) mod pp;
    for i := 1 to m do
        writeln(res[i]);
    halt(0);
end.