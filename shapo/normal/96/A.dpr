program Project2;

{$APPTYPE CONSOLE}

uses
  Math,SysUtils;

var i,num:longint;
    s:string;

begin
    readln(s);
    num:=1;
    for i:=2 to length(s) do begin
        if s[i]=s[i-1] then inc(num) else num:=1;
        if num>=7 then begin
            writeln('YES');
            halt(0);
        end;
    end;
    writeln('NO');
    halt(0);
end.