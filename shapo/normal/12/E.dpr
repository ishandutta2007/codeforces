program task;

{$APPTYPE CONSOLE}

uses
  Math,
  SysUtils;

var i,j,k,n:longint;
    a:array[1..1000,1..1000]of longint;

begin
    readln(n);
    for i:=2 to n do
        a[1,i]:=i-1;
    for i:=2 to n -1 do begin
        k:=i-1;
        for j:= 1 to n-1 do begin
            a[i,j]:=k;
            if i=j then begin
                a[i,j]:=0;
                a[i,n]:=k;
            end;
            inc(k);
            if k=n then k:=1;
        end;
    end;
    a[n,1]:=n-1;
    j:=2;
    i:=2;
    while (j) < n do begin
        a[n,i]:=j;
        inc(j,2);
        inc(i);
    end;
    j:=1;
    while (j)<n-1 do begin
        a[n,i]:=j;
        inc(j,2);
        inc(i);
    end;
    for i:= 1 to n do begin
        for j:= 1 to n do
            write(a[i,j], ' ');
        writeln;
    end;
    halt(0);
end.