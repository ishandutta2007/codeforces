{$MAXSTACKSIZE 04000000}
{$APPTYPE CONSOLE}
{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}

uses Math,SysUtils;

const maxn = 200000;
      maxm = 2 * maxn;

type ver = record
    x : longint;
    bool : boolean;
    next : longint;
end;

var n, i, a, b, c, num : longint;
    beg, en, par, number : array[1..maxn] of longint;
    sm : array[1..maxm] of ver;
    res : int64;
    pp : array[1..maxn] of boolean; 
    d1, d2, cc : array[1..maxn] of int64;
    used : array[1..maxn] of boolean;

procedure init;
var i : longint;
begin
    for i := 1 to maxn do begin
        d1[i] := 0;
        d2[i] := 0;
        cc[i] := 0;
        beg[i] := 0;
        en[i] := 0;
        par[i] := 0;
        number[i] := 0;
        used[i] := false;
    end;
    res := 0;
    num := 0;
end;

function is_happy(u : longint) : boolean;
var i : longint;
    res : boolean;
begin
    res := true;
    i := u;
    while (i > 0) do begin
        res := res and ((i mod 10 = 4) or (i mod 10 = 7));
        i := i div 10;
    end;
    is_happy := res;
end;

procedure add(x, y, z : longint);
begin
    inc(num);
    sm[num].x := y;
    sm[num].bool := is_happy(z);
    if beg[x] = 0 then beg[x] := num;
    if en[x] <> 0 then sm[en[x]].next := num;
    inc(number[x]);
    en[x] := num;
    sm[num].next := 0;
end;

procedure DFS(x, y : longint; ll : boolean);
var i : longint;
begin
    used[x] := true;
    par[x] := y;
    pp[x] := ll;
    i := beg[x];
    while i <> 0 do begin
        if not used[sm[i].x] then begin
            DFS(sm[i].x, x, sm[i].bool);
            cc[x] := cc[x] + cc[sm[i].x];
            if sm[i].bool then begin
                d1[x] := d1[x] + cc[sm[i].x];
                //d2[sm[i].x] := d2[sm[i].x] - cc[sm[i].x];
            end
            else begin
                d1[x] := d1[x] + d1[sm[i].x];
                //d2[sm[i].x] := d2[sm[i].x] - d1[sm[i].x];
            end;
        end;
        i := sm[i].next;
    end;
    cc[x] := cc[x] + 1;
end;

procedure DFS1(x : longint);
var i : longint;
    a1, b1 : int64;
begin
    used[x] := true;
    i := beg[x];
    if par[x]<>0 then begin
        if pp[x] then d2[x]:= n - cc[x]
        else
        d2[x] := d2[par[x]] + d1[par[x]] - d1[x];
    end;
    while i <> 0 do begin
        if not used[sm[i].x] then DFS1(sm[i].x);
        i := sm[i].next;
    end;
    d2[x]:=d2[x]+d1[x];
    a1:=max(d2[x],0);
    b1 := a1 - 1;
    res := res + (a1 * b1);
end;

begin
    readln(n);
    if n <= 1 then writeln(0) else begin
        for i := 1 to n - 1 do begin
            read(a, b, c);
            add(a, b, c);
            add(b, a, c);
        end;
        i := 1;
        while (number[i] <> 1) do inc(i);
        DFS(i, 0, false);
        fillchar(used, sizeof(used), false);
        i := 1;
        while (number[i] <> 1) do inc(i);
        DFS1(i);
        writeln(res);
    end;
    halt(0);
end.