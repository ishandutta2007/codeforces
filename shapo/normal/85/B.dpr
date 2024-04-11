program b;

{$APPTYPE CONSOLE}

uses
  Math,
  SysUtils;

const maxn = 200000;
      maxk = 1 shl 17;
      maxp = maxk - 1;

type check = record
    time : int64;
    x : integer;
end;

var k1, k2, k3 : integer;
    t1, t2, t3 : int64;
    t_1, t_2, t_3 : integer;
    n, i : integer;
    c : array[1..maxn] of integer;
    one, two, three : array[1..maxk + maxp] of check;
    num, tm, maxt : int64;
    res : array[1..maxn] of int64;

function srvn(a, b : check) : check;
begin
    if a.time <= b.time then srvn := a else srvn := b;
end;

procedure init;
var i : integer;
begin
    for i := maxk + k1 to maxp + maxk do begin
        one[i].time := num * tm;
        one[i].x := 0;
    end;
    for i := maxk + k2 to maxp + maxk do begin
        two[i].time := num * tm;
        two[i].x := 0;
    end;
    for i := maxk + k3 to maxp + maxk do begin
        three[i].time := num * tm;
        three[i].x := 0;
    end;
    for i := maxk to maxp + k1 do begin
        one[i].time := 0;
        one[i].x := i - maxp;
    end;
    for i := maxk to maxp + k2 do begin
        two[i].time := 0;
        two[i].x := i - maxp;
    end;
    for i := maxk to maxp + k3 do begin
        three[i].time := 0;
        three[i].x := i - maxp;
    end;
    for i := maxp downto 1 do begin
        one[i] := srvn(one[i * 2], one[i * 2 + 1]);
        two[i] := srvn(two[i * 2], two[i * 2 + 1]);
        three[i] := srvn(three[i * 2], three[i * 2 + 1]);
    end;
end;

function obr(u : int64) : int64;
var res, beg : int64;
    l : integer;
    cur : check;
begin
    beg := u;
    res := u;
    cur := one[1];
    res := max(one[cur.x + maxp].time, res);
    one[cur.x + maxp].time := res + t1;
    res := res + t1;
    l := (cur.x + maxp) div 2;
    while (l <> 0) do begin
        one[l] := srvn(one[l * 2], one[l * 2 + 1]);
        l := l div 2;
    end;
    cur := two[1];
    res := max(two[cur.x + maxp].time, res);
    two[cur.x + maxp].time := res + t2;
    res := res + t2;
    l := (cur.x + maxp) div 2;
    while (l <> 0) do begin
        two[l] := srvn(two[l * 2], two[l * 2 + 1]);
        l := l div 2;
    end;
    cur := three[1];
    res := max(three[cur.x + maxp].time, res);
    three[cur.x + maxp].time := res + t3;
    res := res + t3;
    l := (cur.x + maxp) div 2;
    while (l <> 0) do begin
        three[l] := srvn(three[l * 2], three[l * 2 + 1]);
        l := l div 2;
    end;
    obr := res - beg;
end;

begin
    readln(k1, k2, k3);
    readln(t_1, t_2, t_3);
    t1 := t_1;
    t2 := t_2;
    t3 := t_3;
    readln(n);
    k1 := min(k1, n);
    k2 := min(k2, n);
    k3 := min(k3, n);
    num := n + 1;
    tm := 1000 * 2000 * 1000;
    init;
    maxt := 0;
    for i := 1 to n do begin
        read(c[i]);
        res[i] := obr(c[i]);
        if res[i] > maxt then maxt := res[i];
    end;
    writeln(maxt);
    readln;
    halt(0);
end.