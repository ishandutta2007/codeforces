var n,m,i,j,k,l,r:longint;
    a:array[0..100+1]of longint;
  begin
    read(n);
    for i:=1 to n do
     read(a[i]);
    read(m);
    for i:=1 to m do
     begin
       read(l,r);
       a[l-1]:=a[l-1]+(r-1);
       a[l+1]:=a[l+1]+(a[l]-r);
       a[l]:=0;
     end;
    for i:=1 to n do
     writeln(a[i]);
  end.