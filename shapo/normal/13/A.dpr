var a,i,x,y:longint;

function res(x,y:longint):longint;
var m,c:longint;
begin
    m:=x;
    c:=0;
    while (m<>0)do begin
        c:=c+m mod y;
        m:=m div y;
    end;
    res:=c;
end;

function nod(a,b:longint):longint;
begin
    if a<b then nod:=nod(b,a) else
        if b=0 then nod:=a else nod:=nod(b,a mod b);
end;

begin
    readln(a);
    y:=a-2;
    x:=0;
    for i:= 2 to a-1 do
        x:=x+res(a,i);
    i:=nod(x,y);
    x:=x div i;
    y:=y div i;
    writeln(x,'/',y);
    halt(0);
end.