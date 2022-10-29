program task;

{$APPTYPE CONSOLE}

uses
  Math,
  SysUtils;

type sort = record
    x, id : longint;
end;

const maxk = 1 shl 17;
      maxp = maxk - 1;
      cnst = 0;

var n, i : longint;
    res, sm : array[1..200000] of longint;
    a : array[1..200000] of sort;
    otr : array[1..maxk + maxp] of longint;

function less(a, b : sort) : boolean;
begin
    less := (a.x < b.x) or ((a.x = b.x) and (a.id < b.id));
end;

procedure qsort(l, r : longint);
var i, j : longint;
    x, buf : sort;
begin
    i := l;
    j := r;
    x := a[random(r - l + 1) + l];
    repeat
        while less(a[i], x) do inc(i);
        while less(x, a[j]) do dec(j);
        if i <= j then begin
            buf := a[i];
            a[i] := a[j];
            a[j] := buf;
            inc(i);
            dec(j);
        end;
    until i > j;
    if i < r then qsort(i, r);
    if l < j then qsort(l, j);
end;

procedure init;
var i : longint;
begin
    for i := 1 to maxp + maxk do
        otr[i] := cnst;
end;

procedure add(u : longint);
var i : longint;
begin
    otr[u + maxp] := a[u].id;
    i := (u + maxp) div 2;
    while (i <> 0) do begin
        otr[i] := max(otr[i * 2], otr[i * 2 + 1]);
        i := i div 2;
    end;
end;

function minotr(l, r : longint) : longint;
var i, j, res1 : longint;
begin
    i := l + maxp;
    j := r + maxp;
    res1 := cnst;
    while (i < j) do begin
        res1 := max(res1, otr[i]);
        res1 := max(res1, otr[j]);
        i := (i + 1) div 2;
        j := (j - 1) div 2;
    end;
    if i = j then res1 := max(res1, otr[i]);
    minotr := res1;
end;

begin
    init;
    readln(n);
    for i := 1 to n do begin
        read(a[i].x);
        a[i].id := i;
    end;
    readln;
    randomize;
    qsort(1, n);
    for i := 1 to n do
        sm[a[i].id] := i;
    for i := n downto 1 do begin
        if sm[i] = 1 then res[i] := -1 else begin
            res[i] := minotr(1, sm[i] - 1);
            if res[i] = cnst then res[i] := -1 else res[i] := -i + res[i] - 1;
        end;
        add(sm[i]);
    end;
    for i := 1 to n do
        write(res[i], ' ');
        writeln;
    halt(0);
end.