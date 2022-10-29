program task;

{$APPTYPE CONSOLE}

uses
  Math,
  SysUtils;

type edge = record
    x,next:longint;
end;

var res:longint;
    n,i,num:longint;
    used:array[1..100]of boolean;
    beg,en:array[1..100]of longint;
    sm1:array[1..100,1..100]of longint;
    sm:array[1..2000]of edge;

procedure add(x,y:longint);
begin
    inc(num);
    sm[num].x:=y;
    sm[num].next:=0;
    if beg[x]=0 then beg[x]:=num;
    if en[x]<>0 then sm[en[x]].next := num;
    en[x]:=num;
end;

procedure DFS(u,v:longint);
var i:longint;
begin
    used[u]:=true;
    i:=beg[u];
    while i<> 0 do begin
        if not used[sm[i].x] then begin
            sm1[v,sm[i].x]:=sm1[v,u]+1;
            DFS(sm[i].x,v);
        end;
        i:=sm[i].next;
    end;
end;

procedure obr(u:longint);
var i,k,j,a,b,mx:longint;
begin
    read(k);
    num:=0;
    fillchar(beg,sizeof(beg),0);
    fillchar(en,sizeof(en),0);
    for i :=1 to k-1 do begin
        read(a,b);
        add(a,b);
        add(b,a);
    end;
    readln;
    for i:= 1 to k do begin
        fillchar(used,sizeof(used),false);
        sm1[i,i]:=0;
        DFS(i,i);
    end;
    mx:=0;
    for i := 1 to k do
        for j := 1 to k do
            mx:=max(mx,sm1[i,j]);
    res:=res+mx;
end;

begin
    assign(input,'input.txt');
    assign(output,'output.txt');
    readln(n);
    res:=0;
    for i:= 1 to n do
        obr(i);
    writeln(res);
    halt(0);
end.