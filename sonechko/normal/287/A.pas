var n,m,i,j,k,ans,l,r:longint;
    a:array[0..4,0..4]of char;
  begin
    for i:=1 to 4 do
     begin
       for j:=1 to 4 do
        read(a[i,j]);
       readln;
     end;
    for i:=2 to 4 do
     for j:=2 to 4 do
      begin
        l:=0;
        if (a[i,j]='.') then inc(l);
        if (a[i-1,j]='.') then inc(l);
        if (a[i-1,j-1]='.') then inc(l);
        if (a[i,j-1]='.') then inc(l);
        if (l<>2) then begin writeln('YES'); halt; end;
      end;
    writeln('NO');
  end.