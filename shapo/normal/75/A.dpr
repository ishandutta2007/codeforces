program Project2;

{$APPTYPE CONSOLE}

uses
  Math,SysUtils;

var a,b,c,a1,b1,c1:longint;

function tr(u:longint):longint;
var m,res,res1:int64;
begin
    m:=u;
    res:=0;
    res1:=0;
    while (m<>0) do begin
        if m mod 10<>0 then res1:=res1*10+m mod 10;
        m := m div 10;
    end;
    while (res1<>0) do begin
        res:=res*10+res1 mod 10;
        res1:=res1 div 10;
    end;
    tr:=res;
end;

begin
    readln(a,b);
    c:=a+b;
    a1:=tr(a);
    b1:=tr(b);
    c1:=tr(c);
    if a1+b1=c1 then writeln('YES') else writeln('NO');
    halt(0);
end.