program e;

{$APPTYPE CONSOLE}       {$O+}

uses
  Math,
  SysUtils;

type voin = record
    x, id : integer;
end;

var n, i : integer;
    a1 : array[1..1000000] of integer;
    a : array[1..1000000] of voin;
    pos : array[1..1000000] of integer;
    s1, s2 : array[0..1000001] of int64;
    res, cur : int64;

procedure qsort(l, r : integer);
var i, j : integer;
    x, buf : voin;
begin
    i := l;
    j := r;
    x := a[random(r - l + 1) + l];
    repeat
        while (a[i].x < x.x) do inc(i);
        while (a[j].x > x.x) do dec(j);
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

function rsq(k : integer) : int64;
var res : int64;
begin
    res := 0;
    while (k >= 0) do begin
        inc(res, s1[k]);
        k := k and (k + 1) - 1;
    end;
    rsq := res;
end;

function rsq1(k : integer) : int64;
var res : int64;
begin
    res := 0;
    while (k >= 0) do begin
        inc(res, s2[k]);
        k := k and (k + 1) - 1;
    end;
    rsq1 := res;
end;

procedure update(k : integer; v, m : int64);
var l : integer;
begin
    l := k;
    while (k < n + 1) do begin
        inc(s1[k], v);
        k := k or (k + 1);
    end;
    while (l < n + 1) do begin
        inc(s2[l], m);
        l := l or (l + 1);
    end;
end;

begin
    readln(n);
    for i := 1 to n do begin
        read(a[i].x);
        a1[i] := a[i].x;
        a[i].id := i;
    end;
    readln;
    randomize;
    qsort(1, n);
    fillchar(s1, sizeof(s1), 0);
    fillchar(s2, sizeof(s2), 0);
    res := 0;
    for i := 1 to n do
        pos[a[i].id] := i;
    for i := n downto 1 do begin
        if (pos[i] <> 1) then begin
            cur := rsq(pos[i]);
            res := res + cur;
            cur := rsq1(pos[i]);
            update(pos[i], cur, 1);
        end
        else begin
            update(pos[i], 0, 1);
        end;
    end;
    writeln(res);
end.