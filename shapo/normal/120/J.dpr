program task;

{$APPTYPE CONSOLE}
{$R+,S+,Q+,O-}

uses
  Math,
  SysUtils;

type point=record
    x,y,id:longint;
end;

var a:array[1..100000]of point;
    ind:array[1..100000]of longint;
    p:array[1..100000] of point;
    n,i,x1,y1:longint;

function less(a,b:point):boolean;
begin
    less:=(a.x<b.x)or((a.x=b.x)and(a.y<b.y));
end;

procedure qsort(l,r:longint);
var i,j:longint;
    x,buf:point;
begin
    i:=l;
    j:=r;
    x:=a[random(r-l+1)+l];
    repeat
        while less(a[i],x)do inc(i);
        while less(x,a[j]) do dec(j);
        if i<=j then begin
            buf:=a[i];
            a[i]:=a[j];
            a[j]:=buf;
            inc(i);
            dec(j);
        end;
    until i>j;
    if i< r then qsort(i,r);
    if l< j then qsort(l, j);
end;

function less1(a,b:point):boolean;
begin
    less1:=(a.y<b.y)or((a.y=b.y)and(a.x<b.x));
end;

procedure qsort1(l,r:longint);
var i,j:longint;
    x,buf:point;
begin
    i:=l;
    j:=r;
    x:=p[random(r-l+1)+l];
    repeat
        while less1(p[i],x) do inc(i);
        while less1(x,p[j]) do dec(j);
        if i<=j then begin
            buf:=p[i];
            p[i]:=p[j];
            p[j]:=buf;
            inc(i);
            dec(j);
        end;
    until i>j;
    if i< r then qsort1(i,r);
    if l< j then qsort1(l, j);
end;

function dist(a,b:point):longint;
begin
    dist:=(b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y);
end;

procedure rec(l,r:longint; var x,y:longint);
var a1,a2,b1,b2:longint;
    i,j,niz:longint;
    c1,c2,num,h:longint;
begin
    if (r - l +1 <=5) then begin
        a1:=l;
        a2:=l+1;
        for i:= l to r-1 do
            for j:=i+1 to r do
                if dist(a[i],a[j]) < dist(a[a1],a[a2]) then begin
                    a1:=i;
                    a2:=j;
                end;
        x:=a1;
        y:=a2;
    end
    else begin
        rec(l, (l+r)div 2, a1, a2);
        rec((l+r)div 2 + 1, r, b1, b2);
        c1:=dist(a[a1],a[a2]);
        c2:=dist(a[b1],a[b2]);
        x:=a1;
        y:=a2;
        if c1 > c2 then begin
            c1:=c2;
            x:=b1;
            y:=b2;
        end;
        c2:=a[(l+r)div 2].x;
        num:=0;
        for i := l to r do
            if (a[i].x - c2) * (a[i].x - c2) <=c1 then begin
                inc(num);
                p[num]:=a[i];
                p[num].id:=i;
            end;
        randomize;
        qsort1(1,num);
        niz:=1;
        for i:=2 to num do begin
            while(niz < i) and ((p[niz].y - p[i].y) * (p[niz].y - p[i].y) >= c1) do inc(niz);
            for j:= niz to i-1 do
                if dist(p[j],p[i]) < c1 then begin
                    c1:=dist(p[j],p[i]);
                    x:=p[j].id;
                    y:=p[i].id;        
                end;
        end;
    end;
end;

begin
    assign(input,'input.txt');
    assign(output,'output.txt');
    readln(n);
    for i:=1 to n do begin
        readln(a[i].x,a[i].y);
        a[i].id:=i;
        ind[i]:=1;
        if a[i].y < 0 then ind[i]:=ind[i]+2;
        if a[i].x <0 then ind[i]:=ind[i]+1;
        a[i].x:=abs(a[i].x);
        a[i].y:=abs(a[i].y);
    end;
    randomize;
    qsort(1,n);
    rec(1,n,x1,y1);
    writeln(a[x1].id,' ',ind[a[x1].id],' ',a[y1].id,' ',5-ind[a[y1].id]);
    halt(0);
end.