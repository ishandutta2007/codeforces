program task;

{$APPTYPE CONSOLE}

uses
  Math,
  SysUtils;

var a:array[1..3,1..3]of longint;
    c:char;
    i,j:longint;
    res:boolean;

begin
    for i:= 1 to 3 do begin
        for j:= 1 to 3 do begin
            read(c);
            if c='.' then a[i,j]:=0 else a[i,j]:=1;
        end;
        readln;
    end;
    res:=true;
    for i:= 1 to 3 do
        for j:=1  to 3 do
            res:=res and(a[i,j]=a[4-i,4-j]);
    if res then writeln('YES') else writeln('NO');
    halt(0);
end.