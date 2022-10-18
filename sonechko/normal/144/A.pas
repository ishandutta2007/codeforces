var n,m,i,j,k,l,r,x:LONGINT;
    a:array[1..100]of longint;
  begin
    read(n);
    l:=1;
    for i:=1 to n do
     begin
      read(a[i]);
      if a[i]<a[l] then l:=i;
     end;
    for i:=1 to n do
     if a[i]=a[l] then l:=i;
    k:=0;
    i:=l;
    while i<n do
     begin
       x:=a[i];
       a[i]:=a[i+1];
       a[i+1]:=x;
       inc(k);
       inc(i);
     end;
    r:=1;
    for i:=1 to n do
     if a[i]>a[r] then r:=i;

    i:=r;
    while i>1 do
     begin
       x:=a[i];
       a[i]:=a[i-1];
       a[i-1]:=x;
       inc(k);
       dec(i);
     end;
    writeln(k);
  end.