var n,m,i,j,k,ans,l,r:longint;
    a:array[1..100,1..100]of longint;
    b:array[1..100]of longint;
  begin
    read(m,n);
    for i:=1 to n do
     begin
      k:=1;
      for j:=1 to m do
       begin
         read(a[i,j]);
         if a[i,j]>a[i,k] then k:=j;
       end;
      inc(b[k]);
     end;
    k:=1;
    for i:=1 to m do
     if b[i]>b[k] then k:=i;
    writeln(k);

  end.