program task;

{$APPTYPE CONSOLE}

uses
  Math,
  SysUtils;

var n,p:longint;
    a:array[0..1]of longint;

function nod(x,y:longint):longint;
begin
    if x<y then nod:=nod(y,x)else
        if y=0 then nod:=x else nod:=nod(y,x mod y);
end;

begin
    readln(a[0],a[1],n);
    p:=0;
    while(nod(n,a[p])<=n)do begin
        dec(n,nod(n,a[p]));
        p:=1-p;
    end;
    writeln(1-p);
    halt(0);
end.