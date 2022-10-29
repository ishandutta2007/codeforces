program task;

{$APPTYPE CONSOLE}

uses
  Math,
  SysUtils;

var l,r,res,cur,prev:int64;

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

begin
    readln(l,r);
    cur:=0;
    res:=0;
    prev:=l-1;
    while (prev<r) do begin
        if cur=0 then cur:=4 else cur:=gen(cur);
        if cur>=l then begin
            res:=res+cur*max(min(cur,r)-prev,0);
            prev:=cur;
        end;
    end;
    writeln(res);
    halt(0);
end.