program task;

{$APPTYPE CONSOLE}
{$O+,R-,S-,Q-,I-,D+}

uses
  Math,
  SysUtils;

type bal=record
    b,r,i:longint;
end;

const maxk= 1 shl 19;
        maxp=maxk-1;

var a:array[1..500000]of bal;
    k:array[1..500000] of bal;
    tree:array[1..maxk+maxp]of longint;
    n,i,cur:longint;
    used:array[1..500000] of boolean;
    res,pp:longint;

procedure init;
var i:longint;
begin
    for i:= 1 to 500000 do
        used[i]:=false;
    for i:= 1 to maxk+maxp do
        tree[i]:=0;
end;

function less(a,b:bal):boolean;
begin
    less:=(a.b<b.b)or((a.b=b.b)and(a.r<b.r))
    or((a.b=b.b)and(a.r=b.r)and(a.i<b.i));
end;

procedure qsort(l,r:longint);
var i,j:longint;
    x,buf:bal;
begin
    i:=l;
    j:=r;
    x:=a[random(r-l+1)+l];
    repeat
        while less(a[i],x) do inc(i);
        while less(x,a[j]) do dec(j);
        if i<=j then begin
            buf :=a[i];
            a[i]:=a[j];
            a[j]:=buf;
            inc(i);
            dec(j);
        end;
    until i>j;
    if i<r then qsort(i,r);
    if l<j then qsort(l,j);
end;

procedure qsort1(l,r:longint);
var i,j:longint;
    x,buf:bal;
begin
    i:=l;
    j:=r;
    x:=k[random(r-l+1)+l];
    repeat
        while less(k[i],x) do inc(i);
        while less(x,k[j]) do dec(j);
        if i<=j then begin
            buf:=k[i];
            k[i]:=k[j];
            k[j]:=buf;
            inc(i);
            dec(j);
        end;
    until i>j;
    if i<r then qsort1(i,r);
    if l<j then qsort1(l,j);
end;

procedure add(x,y:longint);
var par:longint;
begin
    tree[x]:=max(tree[x],y);
    par:=x div 2;
    while par <> 0 do begin
        tree[par]:=max(tree[par*2],tree[par*2+1]);
        par:=par div 2;
    end;
end;

function minotr(l,r:longint):longint;
var res:longint;
    l1,r1:longint;
begin
    l1:=l;
    r1:=r;
    res:=0;
    while (l1<r1)do begin
        res:=max(res,max(tree[l1],tree[r1]));
        l1:=(l1+1)div 2;
        r1:=(r1-1)div 2;
    end;
    if l1=r1 then res:=max(res,tree[l1]);
    minotr:=res;
end;

begin
    //assign(input,'input.txt');
    readln(n);
    for i:= 1 to n do
        read(a[i].b);
    for i:= 1 to n do
        read(a[i].r);
    for i:= 1 to n do
        read(a[i].i);
    randomize;
    qsort(1,n);
    for i:= 1 to n do begin
        k[i].b:=a[i].r;
        k[i].r:=i;
        k[i].i:=0;
    end;
    qsort1(1,n);
    cur:=1;
    a[k[1].r].r:=1;
    for i:= 2 to n do begin
        if k[i].b<>k[i-1].b then inc(cur);
        a[k[i].r].r:=cur;
    end;
    init;
    for i:=n downto 1 do begin
        add(a[i].r+maxp,a[i].i);
        if (i<>1)and(a[i].b<>a[i-1].b) then begin
            cur:=i;
            repeat
                dec(cur);
                pp:=minotr(a[cur].r+maxk,maxk+maxp);
                used[cur]:=pp>a[cur].i;
            until (cur=1)or(a[cur].b<>a[cur-1].b);
        end;
    end;
    res:=0;
    for i:= 1 to n do
        if used[i] then inc(res);
    writeln(res);
    halt(0);
end.