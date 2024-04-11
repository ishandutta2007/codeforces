var n,m,i,j,k,l,r:longint;
    a:array[2..10000000+100]of boolean;
  begin
    read(n);
    k:=0;
    for i:=1 to 10000000 do
     a[i]:=true;
    for i:=2 to 10000000 do
     if a[i] then
      begin
        write(i,' ');
        inc(k);
        if k=n then halt;
        j:=i;
        while j<=10000000 do
         begin
           a[j]:=false;
           j:=j+i;
         end;
      end;
    if k<>n then writeln('bob');
  end.