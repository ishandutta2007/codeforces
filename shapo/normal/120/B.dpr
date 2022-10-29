program task;

{$APPTYPE CONSOLE}

uses
  Math,
  SysUtils;

var n,k,i:longint;
    a:array[1..1000]of longint;

begin
    assign(input,'input.txt');
    assign(output,'output.txt');
    readln(n,k);
    for i:= 1 to n do
        read(a[i]);
    while a[k]<>1 do begin
        if k = n then k := 1 else k:=k+1;
    end;
    writeln(k);
end.