var s,t,s1,t1:string;
    n,k,i,j,l,r:longint;
    a:array[1..100000]of char;
  begin
    readln(n,k);
    readln(s);

    for i:=k+1 to n do
     inc(l);
    inc(l);
    for i:=n-1 downto 1 do
     begin
       inc(l,2);
     end;

    for i:=k-1 downto 1 do
     inc(r);
    inc(r);
    for i:=2 to n do
     inc(r,2);

    if l<r then
     begin
        for i:=k+1 to n do
     writeln('RIGHT');
    writeln('PRINT ',s[n]);
    for i:=n-1 downto 1 do
     begin
       writeln('LEFT');
       writeln('PRINT ',s[i]);
     end;
     end else
     begin
        for i:=k-1 downto 1 do
         writeln('LEFT');
       writeln('PRINT ',s[1]);
    for i:=2 to n do
     begin
       writeln('RIGHT');
       writeln('PRINT ',s[i]);
     end;
     end;

  end.