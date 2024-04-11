program Project2;

{$APPTYPE CONSOLE}

uses
  Math,SysUtils;

var n,d,i,j,res:longint;
    a:array[1..1000]of longint;

begin
    readln(n,d);
    for i:=1 to n do
        read(a[i]);
    readln;
    res:=0;
    for i:=1 to n-1 do
        for j:=i+1 to n do
            if abs(a[j]-a[i])<=d then res:=res+2;
    writeln(res);
    halt(0);
end.