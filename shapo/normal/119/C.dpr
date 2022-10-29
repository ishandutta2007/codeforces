program task;
//{$APPTYPE DELPHI}
//{$APPTYPE CONSOLE}
{$R-,S-,Q-,I-,O+}

uses
  Math,
  SysUtils;

type kat=record
    a,b:int64;
    c,id:longint;
end;

var n,m,k,i,jj,l,i1,i2:longint;
    j,kkl,lk,rip:int64;
    kk:array[1..100]of kat;
    least:array[1..100]of longint;
    res:array[1..100,1..50,0..100]of int64;

function less(a,b:kat):boolean;
begin
    less:=(a.c<b.c)or((a.c=b.c)and(a.b<b.b));
end;

procedure bubble;
var i,j:longint;
    cc:kat;
begin
    for i:=2to m do
        for j:=m downto i do
            if less(kk[j],kk[j-1])then begin
                cc:=kk[j];
                kk[j]:=kk[j-1];
                kk[j-1]:=cc;
            end;
end;

procedure dls;
var i, j:longint;
begin
    for i:= 1 to m do begin
        j:=0;
        while (kk[j+1].c<kk[i].c) do inc(j);
        least[i]:=j;
    end;
end;

procedure init;
var i,j,k:longint;
begin
    for j:= 1 to 50 do
        for i:=1 to 100 do
            for k := 0 to 100 do
                res[i,j,k]:=0;
end;

procedure obr(x, y : longint;z:int64);
var j, kkl,lk : int64;
    ok:boolean;
begin
    ok:=false;
    if (x = 1) then
        writeln(kk[y].id,' ',z+kk[y].a)
    else begin
        j := z;
        kkl := kk[y].a+j;
        if kkl mod int64(k) = 0 then begin
            lk := kkl div int64(k);
            l:=1;
            while (not ok) and (l<=least[y]) do begin
                if (lk>=kk[l].a)and(lk<=kk[l].b)and(res[l,x-1,lk-kk[l].a]<>0)and
                (res[y,x,z]=res[l,x-1,lk-kk[l].a]+kkl)then begin
                    ok:=true;
                    obr(x-1,l,lk-kk[l].a);
                    writeln(kk[y].id,' ',z+kk[y].a);
                end;
                l:=l+1;
            end;
        end;
            lk:=kkl-int64(k);
            l:=1;
            while (not ok) and (l<=least[y]) do begin
                if (lk>=kk[l].a)and(lk<=kk[l].b)and(res[l,x-1,lk-kk[l].a]<>0)and
                (res[y,x,z]=res[l,x-1,lk-kk[l].a]+kkl)then begin
                    ok:=true;
                    obr(x-1,l,lk-kk[l].a);
                    writeln(kk[y].id,' ',z+kk[y].a);
                end;
                l:=l+1;
            end;
        end;
end;

begin
    //assign(input,'input.txt');
    //assign(output, 'output.txt');
    init;
    readln(n,m,k);
    for i := 1 to m do
        kk[i].id := i;
    for i:=1to m do
        readln(kk[i].a,kk[i].b,kk[i].c);
    bubble;
    for i:=1 to m do begin
        kkl:=kk[i].a;
        j:=0;
        //jj:=1;
        while kkl<=kk[i].b do begin
            res[i,1,j]:=kkl;
            //writeln('res :', jj, ':',i, ':', j, ' is ', res[i,jj,j]);
            j:=j+1;
            kkl:=kkl+1;
        end;
    end;
    dls;
    for jj:=2 to n do begin
        for i:=1to m do begin
            kkl:=kk[i].a;
            j:=0;
            while (kkl<=kk[i].b)do begin
                kkl:=j+kk[i].a;
                if kkl mod int64(k) = 0 then begin
                    lk:=kkl div int64(k);
                    for l:=1 to least[i] do
                    if (lk>=kk[l].a)and(lk<=kk[l].b)and(res[l,jj-1,lk-kk[l].a]<>0)then
                        res[i,jj,j]:=max(res[i,jj,j], res[l,jj-1,lk-kk[l].a]+kkl);
                end;
                lk:=kkl-int64(k);
                for l:=1 to least[i] do
                if (lk >= kk[l].a)and(lk<=kk[l].b)and(res[l,jj-1,lk-kk[l].a]<>0)then
                    res[i,jj,j]:=max(res[i,jj,j], res[l,jj-1,lk-kk[l].a]+kkl);
                kkl:=kkl+1;
                //writeln('res :', jj, ':',i, ':', j, ' is ', res[jj,i,j]);
                j:=j+1;
            end;
        end;
    end;
    rip:=0;
    i1:=0;
    i2:=0;
    for i:=1to m do begin
        kkl:=kk[i].a;
        j:=0;
        while(kkl<=kk[i].b)do begin
            rip:=max(rip,res[i,n,j]);
            if rip=res[i,n,j] then begin
                i1:=i;
                i2:=j;
            end;
            j:=j+1;
            kkl:=kkl+1;
        end
    end;
    if rip = 0 then writeln('NO') else begin
        writeln('YES');
        //writeln(rip,' ',i1, ' ',i2);
        obr(n, i1, i2);
    end;
    halt(0)
end.