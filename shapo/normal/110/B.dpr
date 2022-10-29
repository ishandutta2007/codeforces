program Project2;

{$APPTYPE CONSOLE}

uses
  Math,SysUtils;

var n,cur,i:longint;

begin
    readln(n);
    cur:=0;
    for i:=1 to n do begin
        write(chr(ord('a')+cur));
        cur:=(cur+1)mod 4;
    end;
    writeln;
    halt(0);
end.