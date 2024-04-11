program Project2;

{$APPTYPE CONSOLE}

uses
  Math,SysUtils;

var s:string;
    n1,n2,i:longint;

begin
    readln(s);
    n1:=0;
    n2:=0;
    for i:=1 to length(s) do begin
        if s[i]='4' then inc(n1);
        if s[i]='7' then inc(n2);
    end;
    if (n1=0) and (n2=0) then writeln('-1') else begin
        if n1>=n2 then writeln('4') else writeln('7');
    end;
    halt(0);
end.