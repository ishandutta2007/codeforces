program task;

{$APPTYPE CONSOLE} {$O+,R+,S+,Q+,I+}

uses
  Math,
  SysUtils;

const maxn = 3 * 100 * 1000;
      maxk = 1 shl 18;
      maxp = maxk - 1;

type list = record
    x, add : int64;
end;

type ver = record
    x, next : longint;
    pp : int64;
end;

type sm = record
    num : longint;
    mass : array[1..2 * maxn] of ver;
    beg, en : array[1..maxn] of longint;
end;

type tree = array[1..maxk + maxp] of list;

var spisok : sm;
    ll : tree;
    a, b : array[0..maxn] of int64;
    cur : array[1..maxn] of int64;
    n, m, i, x, y, z : longint;

procedure init;
var i : longint;
begin
    for i := 1 to maxk + maxp do begin
        ll[i].x := 0;
        ll[i].add := 0;
    end;
    for i := 1 to maxn do begin
        spisok.beg[i] := 0;
        spisok.en[i] := 0;
    end;
    spisok.num := 0;
end;

procedure add(x, y, z : longint);
begin
    inc(spisok.num);
    spisok.mass[spisok.num].x := y;
    spisok.mass[spisok.num].next := 0;
    spisok.mass[spisok.num].pp := z;
    if spisok.beg[x] = 0 then spisok.beg[x] := spisok.num;
    if spisok.en[x] <> 0 then spisok.mass[spisok.en[x]].next := spisok.num;
    spisok.en[x] := spisok.num;
end;

function max_res(x, y : list) : list;
var res : list;
begin
    if x.x + x.add > y.x + y.add then begin
        res.x := x.x + x.add;
        res.add := 0;
    end
    else begin
        res.x := y.x + y.add;
        res.add := 0;
    end;
    max_res := res;
end;

procedure add_to_tree(l, r, l1, r1, v : longint; ud : int64);
begin
    if max(l, l1) <= min(r, r1) then begin
        if (l <= l1) and (r >= r1) then ll[v].add := ll[v].add + ud
        else begin
            //writeln('v :', v, ' l:', l, ' l1: ', l1, ' r:', r, ' r1:', r1);
            ll[2 * v].add := ll[2 * v].add + ll[v].add;
            ll[2 * v + 1].add := ll[2 * v + 1].add + ll[v].add;
            ll[v].add := 0;
            add_to_tree(l, r, l1, (l1 + r1) div 2, v * 2, ud);
            add_to_tree(l, r, (l1 + r1) div 2 + 1, r1, v * 2 + 1, ud);
            ll[v] := max_res(ll[2 * v], ll[2 * v + 1]);
        end;
    end;
end;

procedure obr(x : longint);
var i : longint;
begin
    i := spisok.beg[x];
    while i <> 0 do begin
        //writeln('add pp: ', spisok.mass[i].pp);
        add_to_tree(1, spisok.mass[i].x, 1, maxk, 1, spisok.mass[i].pp);
        //writeln('tree: ', ll[1].x + ll[1].add);
        i := spisok.mass[i].next;
    end;
end;

begin
    //assign(input, 'input.txt');
    init;
    readln(n, m);
    for i := 1 to n do
        readln(cur[i]);
    for i := 1 to m do begin
        readln(x, y, z);
        add(y, x, z);
    end;
    a[0] := 0;
    b[0] := 0;
    for i := 1 to n do begin
        if a[i - 1] > b[i - 1] then b[i] := a[i - 1]
        else b[i] := b[i - 1];
        add_to_tree(1, i, 1, maxk, 1, -cur[i]);
        obr(i);
        a[i] := ll[1].x + ll[1].add;
        add_to_tree(i + 1, i + 1, 1, maxk, 1, b[i]);
    end;
    if a[n] > b[n] then writeln(a[n]) else writeln(b[n]);
    halt(0);
end.