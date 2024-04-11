program c;

{$APPTYPE CONSOLE}
{$MAXSTACKSIZE 02000000}

{$O+}

uses
  Math,
  SysUtils;

type tree = record
    l, r, par : integer;
    x : extended;
end;

type ver = record
    x : extended;
    id : integer;
end;

type sum = record
    x, k : extended;
end;

const maxn = 200000;
      maxk = 1 shl 18;
      maxp = maxk - 1;

var n, i, k : integer;
    bin : array[1..maxn] of tree;
    sm : array[1..maxn] of ver;
    res : array[1..maxk + maxp] of sum;
    res1 : array[1..maxn] of extended;
    root : integer;
    left, right : array[1..maxn] of extended;

procedure lft(u : integer);
begin
    if bin[u].l <> 0 then begin
        lft(bin[u].r);
        lft(bin[u].l);
        left[u] := left[bin[u].l];
    end
    else left[u] := bin[u].x;
end;

procedure rght(u : integer);
begin
    if bin[u].r <> 0 then begin
        rght(bin[u].l);
        rght(bin[u].r);
        right[u] := right[bin[u].r];
    end
    else right[u] := bin[u].x;
end;

function less(a, b : ver) : boolean;
begin
    less := a.x < b.x;
end;

procedure qsort(l, r : integer);
var i, j : integer;
    x, buf : ver;
begin
    i := l;
    j := r;
    x := sm[random(r - l + 1) + l];
    repeat
        while less(sm[i], x) do inc(i);
        while less(x, sm[j]) do dec(j);
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

procedure add_sum(l, r, l1, r1, a: integer; c : extended);
begin
    if (l <= r) and (max(l1, l) <= min(r1, r)) then begin
        if (l1 >= l) and (r1 <= r) then begin
            res[a].x := res[a].x + c;
            res[a].k := res[a].k + 1;
        end
        else begin
            add_sum(l, r, l1, (l1 + r1) div 2, a * 2, c);
            add_sum(l, r, ((l1 + r1) div 2) + 1, r1, a * 2 + 1, c);
        end;
    end;
end;

procedure obr(u, l1, r1 : integer);
var lk, rk, mp, m, lp, rp : integer;
begin
    if (bin[u].l <> 0) and (l1 <= r1) then begin
        lk := l1;
        rk := r1;
        lp := lk;
        rp := rk;
        if sm[rk].x < bin[u].x then m := rk else begin
            while (lp < rp - 1) do begin
                mp := (lp + rp) div 2;
                if sm[mp].x < bin[u].x then lp := mp else rp := mp;
            end;
            if (sm[lp].x < bin[u].x) then m := lp else m := lp - 1;
        end;
        add_sum(lk, m, 1, maxk, 1, left[bin[u].r]);
        add_sum(m + 1, rk, 1, maxk, 1, right[bin[u].l]);
        if bin[u].l <> 0 then obr(bin[u].l, lk, m);
        if bin[u].r <> 0 then obr(bin[u].r, m + 1, rk);
    end;
end;

begin
    //assign(input, 'c.in');
    //assign(output, 'c.out');
    readln(n);
    //n := 99999;
    fillchar(bin, sizeof(bin), 0);
    for i := 1 to maxk + maxp do begin
        res[i].x := 0;
        res[i].k := 0;
    end;
    for i := 1 to n do
        readln(bin[i].par, bin[i].x);
//    bin[1].par := -1;
//    bin[1].x := 3;
    //for i := 2 to n do begin
    //    if i mod 2 = 0 then bin[i].par := i - 1 else bin[i].par := i - 2;
  //      if i mod 2 = 0 then bin[i].x := i else bin[i].x := i + 2;
//    end;
    root := 1;
    for i := 1 to n do
        if bin[i].par <> -1 then begin
            if bin[bin[i].par].x < bin[i].x then bin[bin[i].par].r := i
            else bin[bin[i].par].l := i;
        end
        else root := i;
    lft(root);
    rght(root);
    readln(k);
    for i := 1 to k do begin
        readln(sm[i].x);
        sm[i].id := i;
    end;
    randomize;
    qsort(1, k);
    obr(root, 1, k);
    for i := 1 to maxp do begin
        res[i * 2].x := res[i * 2].x + res[i].x;
        res[i * 2].k := res[i * 2].k + res[i].k;
        res[i * 2 + 1].x := res[i * 2 + 1].x + res[i].x;
        res[i * 2 + 1].k := res[i * 2 + 1].k + res[i].k;
    end;
    for i := 1 to k do
        if (res[i + maxp].k <> 0) then res1[sm[i].id] := res[i + maxp].x / res[i + maxp].k
        else res1[sm[i].id] := 0;
    for i := 1 to k do
        writeln(res1[i] : 0 : 9);
    halt(0);
end.