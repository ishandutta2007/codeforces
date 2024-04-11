var n,m,i,j,k,l,r:longint;
    a:array[1..1000]of longint;
  begin
    read(n);
    for i:=1 to n do
     begin
       read(a[i]);
       if a[i]>m then m:=a[i];
     end;
    k:=2;
    l:=maxlongint;
    for i:=2 to n-1 do
     begin
       r:=0;
       for j:=2 to n do
        if (j<>i) and (j<>i+1) and (a[j]-a[j-1]>r) then r:=a[j]-a[j-1];
       if a[i+1]-a[i-1]>r then r:=a[i+1]-a[i-1];
       if r<l then begin l:=r; k:=i; end;
     end;
    writeln(l);
  end.