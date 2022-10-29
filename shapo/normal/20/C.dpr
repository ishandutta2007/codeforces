program task;

{$APPTYPE CONSOLE}
{$O+,R-,S-,Q-,I-}

uses
  Math,
  SysUtils;

const maxk=1 shl 17;
    maxp=maxk-1;
    maxn=100000;

type list=record
    x:int64;
    v:longint;
end;

type edge=record
    x,next:longint;
    w:int64;
end;

var sm:array[1..2*maxn]of edge;
    num,n,m,i,a,b,c,nn,cur:longint;
    c_l:list;
    st:array[0..maxn]of longint;
    beg,en:array[1..maxn]of longint;
    res:array[1..maxn]of int64;
    pr:array[1..maxn]of longint;
    used:array[1..maxn]of boolean;
    tree:array[1..maxk+maxp]of list;

procedure init;
var i:longint;
begin
    num:=0;
    for i:= 1 to maxn do begin
        pr[i]:=-1;
        used[i]:=false;
        res[i]:=int64(1000000)*int64(1000000);
        beg[i]:=0;
        en[i]:=0;
    end;
    for i:=1to maxk+maxp do begin
        tree[i].x:=res[1];
        tree[i].v:=1;
    end;
end;

procedure add(x,y:longint;z:int64);
begin
    inc(num);
    sm[num].x:=y;
    sm[num].w:=z;
    sm[num].next:=0;
    if beg[x]=0 then beg[x]:=num;
    if en[x]<>0 then sm[en[x]].next:=num;
    en[x]:=num;
end;

function min_list(a,b:list):list;
begin
    if a.x < b.x then min_list:=a else min_list:=b;
end;

procedure update(x:longint;y:int64);
var par:longint;
begin
    tree[x+maxp].x:=y;
    tree[x+maxp].v:=x;
    par:=(x+maxp)div 2;
    while par<>0 do begin
        tree[par]:=min_list(tree[2*par],tree[2*par+1]);
        par:=par div 2;
    end;
end;

begin
    //assign(input,'input.txt');
    init;
    readln(n,m);
    for i:=1 to m do begin
        readln(a,b,c);
        add(a,b,c);
        add(b,a,c);
    end;
    update(1,0);
    while true do begin
        c_l:=tree[1];
        if c_l.x=int64(1000000)*int64(1000000) then break;
        used[c_l.v]:=true;
        res[c_l.v]:=c_l.x;
        update(c_l.v,int64(1000000)*int64(1000000));
        i:=beg[c_l.v];
        while i<>0 do begin
            cur:=sm[i].x;
            if not used[cur] and (tree[maxp+cur].x>res[c_l.v]+sm[i].w) then begin
                update(cur,res[c_l.v]+sm[i].w);
                pr[cur]:=c_l.v;
            end;
            i:=sm[i].next;
        end;
    end;
    if pr[n]=-1 then writeln(-1) else begin
        nn:=0;
        cur:=n;
        while (cur<>-1) do begin
            inc(nn);
            st[nn]:=cur;
            cur:=pr[cur];
        end;
        for i:=nn downto 1 do
            write(st[i],' ');
        writeln;
    end;
    halt(0);
end.