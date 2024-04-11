{$APPTYPE CONSOLE}
var n,i,ind:longint;
    a:array[1..100000] of longint;
procedure qsort(l,r:longint);
var i,j,x,buf:longint;
begin
    i:=l;
    j:=r;
    x:=a[random(r-l+1)+l];
    repeat
        while a[i]<x do inc(i);
        while x<a[j] do dec(j);
        if i<= j then begin
            buf :=a[i];
            a[i]:=a[j];
            a[j]:=buf;
            inc(i);
            dec(j);
        end;
    until i>j;
    if i<r then qsort(i,r);
    if l<j then qsort(l,j);
end;
begin
    ind:=1;
    readln(n);
    for i:= 1 to n do begin
        read(a[i]);
    end;
    randomize;
    qsort(1,n);
    for i:= 2 to n do
        if (a[i]<>a[i-1]) and (a[i] div 2<a[i-1]) then begin
            writeln('YES');
            halt(0);
        end;
    writeln('NO');
    halt(0);
end.