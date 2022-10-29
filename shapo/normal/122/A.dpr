program Project2;

{$APPTYPE CONSOLE}

uses
  Math,SysUtils;

var n,i:longint;

function lucky(u:longint):boolean;
var res:boolean;
    m:longint;
begin
    m:=u;
    res:=true;
    while (m<> 0) do begin
        res:=res and ((m mod 10=4)or(m mod 10=7));
        m:=m div 10;
    end;
    lucky:=res;
end;

begin
    readln(n);
    for i:= 1 to n do
        if lucky(i) and (n mod i=0) then begin
            writeln('YES');
            halt(0);
        end;
    writeln('NO');
    halt(0);
end.