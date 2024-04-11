program Project2;

{$APPTYPE CONSOLE}

uses
  Math,SysUtils;

var n,i,j,cur,max,num:longint;
    a:array[1..1000]of longint;

begin
    readln(n);
    for i:=1 to n do
        read(a[i]);
    readln;
    for i:=2 to n do
        for j:= n downto i do
            if a[j]<a[j-1]then begin
                cur:=a[j];
                a[j]:=a[j-1];
                a[j-1]:=cur;
            end;
    num:=1;
    cur:=1;
    max:=cur;
    for i:=2 to n do begin
        if a[i]=a[i-1] then begin
            inc(cur);
            if max<cur then max:=cur;
        end
        else begin
            inc(num);
            cur:=1;
        end;
    end;
    writeln(max,' ',num);
    halt(0);
end.