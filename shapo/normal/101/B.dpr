program task;

{$APPTYPE CONSOLE}

uses
  Math,
  SysUtils;

const pp = 1000 * 1000 * 1000 + 7;
      maxk = 1 shl 17;
      maxp = maxk - 1;

type sort = record
    x, id : int64;
end;

var sm : array[1..2 * 300000] of sort;
    cur : array[1..200000] of int64;
    a, b, i, n, m, l1, r1, m1, lp, rp, pn : longint;
    ans : int64;
    res : array[1..2 * 300000] of int64;

procedure qsort(l, r : longint);
var i, j : longint;
     x, buf : sort;
begin
    i := l;
    j := r;
    x := sm[random(r - l + 1) + l];
    repeat
        while (sm[i].x < x.x) do inc(i);
        while (x.x < sm[j].x) do dec(j);
        if i <= j then begin
            buf := sm[i];
            sm[i] := sm[j];
            sm[j] := buf;
            inc(i);
            dec(j);
        end;
    until i > j;
    if i < r then qsort(i, r);
    if l < j then qsort(l, j);
end;

procedure update(x : longint);
var u : longint;
begin
    u := (x + maxp) div 2;
    while u <> 0 do begin
        res[u] := (res[2 * u] + res[2 * u + 1]) mod pp;
        u := u div 2;
    end;
end;

function sum(l, r : longint) : int64;
var ans1 : int64;
    l1, r1 : longint;
begin
    l1 := l + maxp;
    r1 := r + maxp;
    ans1 := 0;
    while (l1 < r1) do begin
        if l1 mod 2 = 1 then ans1 := ans1 + res[l1];
        if r1 mod 2 = 0 then ans1 := ans1 + res[r1];
        l1 := (l1 + 1) div 2;
        r1 := (r1 - 1) div 2;
    end;
    if l1 = r1 then ans1 := ans1 + res[l1];
    sum := ans1;
end;

begin
    readln(n, m);
    sm[1].x := 0;
    sm[1].id := 1;
    for i := 1 to m do begin
        readln(a, b);
        sm[i + 1].x := b;
        sm[i + 1].id := i + 1;
        cur[i + 1] := a;
    end;
    sm[m + 2].x := 0;
    randomize;
    qsort(1, m + 1);
    ans := 0;
    for i := 1 to maxk + maxp do
        res[i] := 0;
    res[maxk] := 1;
    update(1);
    pn := 2;
    for i := 2 to m + 1 do begin
        if sm[i].x <> sm[pn].x then pn := i;
        if cur[sm[i].id] <= sm[i - 1].x then begin
            l1 := 0;
            r1 := i - 1;
            while (l1 < r1 - 1) do begin
                m1 := (l1 + r1) div 2;
                if sm[m1].x >= cur[sm[i].id] then r1 := m1 else l1 := m1;
            end;
            lp := r1;
            rp := pn - 1;
            res[maxp + i] := sum(lp, rp);
            update(i);
            //writeln('sear: ', lp, ' ', rp);
            //writeln(pn, ' ', sm[pn].x);
        end;
    end;
    for i := 1 to m + 1 do
        if (sm[i].x = n) then ans := (ans + res[maxp + i]) mod pp;
    writeln(ans);
    halt(0);
end.