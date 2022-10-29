program task;

{$APPTYPE CONSOLE}
{$O+}

uses
  Math,
  SysUtils;

var n,k:int64;
    res:int64;
    cur,i,curi,ppc:int64;
    l:int64;
    used:array[1..13]of boolean; // numbers from(n-12)to n

function gen(x:int64):int64;
var n:longint;
    m,res:int64;
begin
    m:=x;
    n:=0;
    while(m<>0)and (m mod 10=7)do begin
        n:=n+1;
        m := m div 10;
    end;
    if m=0 then begin
        res:=0;
        n:=n+1;
        while (n<>0) do begin
            res:=res*10+4;
            n:=n-1;
        end;
    end
    else begin
        res:=(m div 10)*10 +7;
        while (n<>0) do begin
            res:=res*10+4;
            n:=n-1;
        end;
    end;
    gen:=res;
end;

function lucky(u:int64):boolean;
var m:int64;
    res:boolean;
begin
    res:=true;
    m:=u;
    while m<>0 do begin
        res:=res and((m mod 10 =4)or(m mod 10=7));
        m:=m div 10;
    end;
    lucky:=res;
end;

function nn(u:int64):longint;
var res:longint;
    cur:int64;
begin
    cur:=4;
    res:=0;
    while (cur<=u) do begin
        inc(res);
        cur:=gen(cur);
    end;
    nn:=res;
end;

function fac(x:int64):int64;
var i,res:int64;
begin
    i:=1;
    res:=1;
    while(i<=x) do begin
        res:=res*i;
        i:=i+1;
    end;
    fac:=res;
end;

begin
    readln(n,k);
    res:=0;
    fillchar(used,sizeof(used),false);
    if n>13 then begin
        res:=res+nn(n-13);
        curi:=n-12;
        l:=1;
    end
    else begin
        curi:=1;
        l:=13-n+1;
        cur:=fac(n);
        if k>cur then begin
            writeln('-1');
            halt(0);
        end;
    end;
    while (curi<=n) do begin
        cur:=fac(n-curi);
        i:=l;
        while (used[i]) do i:=i+1;;
        ppc:=cur;
        while (ppc<k) do begin
            i:=i+1;
            while (used[i]) do i:=i+1;
            ppc:=ppc+cur;
        end;
        used[i]:=true;
        if lucky(curi)and(lucky(n+i-13)) then res:=res+1;
        curi:=curi+1;
        k:=k-(ppc-cur);
    end;
    writeln(res);
    halt(0);
end.