program Project2;

{$APPTYPE CONSOLE}

uses
  Math,SysUtils;

var n,m,i,j,a,b,c,d:longint;
    cur:array[1..50,1..50]of char;

begin
    a:=51;
    b:=0;
    c:=51;
    d:=0;
    readln(n,m);
    for i:=1 to n do begin
        for j:= 1 to m do begin
            read(cur[i,j]);
            if cur[i,j]='*' then begin
                a:=min(a,i);
                b:=max(b,i);
                c:=min(c,j);
                d:=max(d,j);
            end;
        end;
        readln;
    end;
    for i:= a to b do begin
        for j:= c to d do
            write(cur[i,j]);
        writeln;
    end;
    halt(0);
end.