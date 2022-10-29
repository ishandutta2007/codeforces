var a:array[1..4]of longint;
    i,j,buf:longint;
begin
    readln(a[1],a[2],a[3],a[4]);
    for i:=2 to 4 do
        for j:=4 downto i do
            if a[j]<a[j-1] then begin
                buf:=a[j];
                a[j]:=a[j-1];
                a[j-1]:=buf;
            end;
    if (a[1]+a[2]>a[3])or(a[1]+a[3]>a[4])or(a[1]+a[2]>a[4])
    or(a[2]+a[3]>a[4]) then begin
        writeln('TRIANGLE');
        halt(0);
    end;
    if (a[1]+a[2]=a[3])or(a[1]+a[3]=a[4])or(a[1]+a[2]=a[4])
    or(a[2]+a[3]=a[4]) then begin
        writeln('SEGMENT');
        halt(0);
    end;        
    writeln('IMPOSSIBLE');
    halt(0);
end.