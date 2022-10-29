program task;             

{$APPTYPE CONSOLE}
{$O+,R-,Q-,S-,I-}

uses
  Math,
  SysUtils;

var a,b,k,nm:longint;
    prime,num:array[1..50000]of longint;
    mn:array[1..50000]of longint;
    used:array[2..50000] of boolean;

procedure init(u:longint);
var i,j:longint;
begin
    mn[1]:=maxlongint;
    for i:=2 to 50000 do
        mn[i]:=i;
    fillchar(used,sizeof(used),true);
    fillchar(num,sizeof(num),0);
    nm:=0;
    for i:= 2 to u do
        if used[i] then begin
            inc(nm);
            prime[nm]:=i;
            num[i]:=nm;
            if (u div i >= i) then j:=i*i else j:=maxlongint;
            while (j<=u) do begin
                mn[j]:=min(mn[j],i);
                used[j]:=false;
                j:=j+i;
            end;
        end;
end;

function res(x,y,z:longint):longint;
var cur,i,p1,ll:longint;
begin
    ll:=max(z,2);
    if (x=0)or(y=0) then cur:=0 else begin
        cur:=x div prime[y];
        p1:=cur;
        if (p1 <= 50000) and (prime[y]<>k) then begin
            cur:=0;
            for i:=1 to p1 do
                if mn[i]>=prime[y]
                then inc(cur);
        end
        else begin
            for i:= 1 to y-1 do
                cur:=cur-res(p1,i,ll);
        end;
    end;
    res:=cur;
end;

function prim(u:longint):boolean;
var ok:boolean;
    i:longint;
begin
    i := 2;
    ok := u=2;
    if not ok then begin
        while (i*i<=u)and(u mod i<>0)do inc(i);
        ok :=u mod i<>0;
    end;
    prim:=ok;
end;

begin
    readln(a,b,k);
    init(50000);
    if not prim(k) then writeln(0) else begin
        if (b div k <k) then begin
            a:=(a+k-1)div k;
            b:=b div k;
            if (a>1)or(b<1) then writeln(0) else writeln(1);
        end
        else
            writeln(res(b,num[k],1)-res(a-1,num[k],1));
    end;
    halt(0);
end.