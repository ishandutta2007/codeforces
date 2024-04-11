program Project2;

{$APPTYPE CONSOLE}

uses
  Math,SysUtils;

var a,b,c,n:longint;

begin
    readln(n);
    a:=n div 36;
    b:=(n mod 36)div 3;
    c:=n mod 3;
    if (c >=2) then inc(b);
    if b=12 then begin
        inc(a);
        b:=0;
    end;
    writeln(a,' ',b);
    halt(0);
end.