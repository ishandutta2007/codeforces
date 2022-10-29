program Project2;

{$APPTYPE CONSOLE}

uses
  Math,SysUtils;

var asis,n,i,mn:longint;
    a:array[1..100]of longint;

begin
    readln(n);
    mn:= 1001;
    for i:= 1 to n do begin
        read(a[i]);
        mn:=min(mn,a[i]);
    end;
    asis:=1001;
    readln;
    for i:= 1 to n do
        if (a[i]>mn) then asis :=min(asis,a[i]);
    if asis=1001 then writeln('NO')
    else
        writeln(asis);
    halt(0);
end.