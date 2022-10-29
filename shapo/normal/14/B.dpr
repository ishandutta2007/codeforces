program Project2;

{$APPTYPE CONSOLE}

uses
  Math,SysUtils;

var n,x,ma,mb:longint;
    a,b,i:longint;

begin
    ma:=-1;
    mb:=1001;
    readln(n,x);
    for i:=1  to n do begin
        readln(a,b);
        ma:=max(ma,min(a,b));
        mb:=min(mb,max(a,b));
    end;
    if (mb<ma) then writeln(-1) else begin
        if (x <= mb) and (x>=ma) then writeln(0)
        else writeln(min(abs(x-ma),abs(x-mb)));
    end;
    halt(0);
end.