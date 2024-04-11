var n,m,i,j,k,l:longint;
    a:array[1..1000000]of longint;
  begin
    read(n,m);
    for I:=1 to m do
     begin
       read(l);
       for j:=l to n do
        if a[j]=0 then a[j]:=l;
     end;
    for i:=1 to n do
     write(a[i],' ');
    writeln;
  end.