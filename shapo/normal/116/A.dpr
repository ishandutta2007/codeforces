program Project2;

{$APPTYPE CONSOLE}

uses
  Math,SysUtils;

var n,i,cur,mn,a,b:longint;

begin
    mn:=0;
    cur:=0;
    readln(n);
    for i:=1 to n do begin
        readln(a,b);
        cur:=cur-a+b;
        mn:=max(cur,mn);
    end;
    writeln(mn);
    halt(0);
end.