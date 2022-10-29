program task;

{$APPTYPE CONSOLE}
{$MAXSTACKSIZE $03000000}

uses
  Math,
  SysUtils;

type edge = record
    x, next : longint;
end;

const maxm = 4 * 100 * 1000;

var n, m : longint;
    sm : array[1..2 * maxm]of edge;
    num:longint;
    beg,en:array[1..100000]of longint;
    used:array[1..100000]of longint;
    tin,tout,d:array[1..100000]of longint;
    nn:longint;
    p,q:array[1..maxm]of longint;
    a,b,i,ti:longint;
    est:boolean;

procedure add(x,y:longint);
begin
    inc(num);
    sm[num].x:=y;
    sm[num].next:=0;
    if beg[x]=0 then beg[x]:=num;
    if en[x]<>0 then sm[en[x]].next:=num;
    en[x]:=num;
end;

procedure DFS(u,v:longint);
var i:longint;
begin
    used[u]:=1;
    inc(ti);
    tin[u]:=ti;
    i:=beg[u];
    while i<>0 do begin
        if used[sm[i].x] = 0 then DFS(sm[i].x,u);
        i:=sm[i].next;
    end;
    inc(ti);
    tout[u]:=ti;
    d[u]:=tin[u];
    i:=beg[u];
    while i<>0 do begin
        if sm[i].x <> v then begin
            if used[sm[i].x] = 2 then begin
                d[u]:=min(d[u],d[sm[i].x]);
                est:=est or(d[sm[i].x]>tin[u]);
            end
            else
                d[u]:=min(d[u],tin[sm[i].x]);
        end;
        i:=sm[i].next;
    end;
    used[u]:=2;
end;

procedure DFS1(u,v:longint);
var i : longint;
begin
    used[u]:=1;
    i:=beg[u];
    while i<>0 do begin
        if (used[sm[i].x] <= 1) and(sm[i].x<>v) then begin
            inc(nn);
            p[nn] := u;
            q[nn] := sm[i].x;
        end;
        if used[sm[i].x] = 0 then DFS1(sm[i].x,u);
        i:=sm[i].next;
    end;
    used[u]:=2;
end;

begin
    //assign(input,'input.txt');
    //assign(output,'output.txt');
    readln(n, m);
    fillchar(beg,sizeof(beg),0);
    fillchar(en,sizeof(en),0);
    fillchar(used,sizeof(used),0);
    num:=0;
    est:=false;
    for i :=1 to m do begin
        readln(a,b);
        add(a,b);
        add(b,a);
    end;
    ti:=0;
    DFS(1,0);
    for i:=1 to n do
        est := est or (used[i] = 0);
    if est then begin
        writeln('0');
        halt(0);
    end;
    fillchar(used,sizeof(used),0);
    nn:=0;
    DFS1(1,0);
    for i:=1 to m do
        writeln(p[i], ' ', q[i]);
    halt(0);
end.