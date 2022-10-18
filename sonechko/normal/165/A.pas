var n,m,i,j,k,ans,l,r,p:longint;
    a,b:array[1..500]of longint;
  begin

    read(n);
    for i:=1 to n do
     read(a[i],b[i]);
    for i:=1 to n do
     begin
       l:=0;
       r:=0;
       k:=0;
       p:=0;
       for j:=1 to n do
        if (a[i]>a[j]) and (b[i]=b[j]) then l:=1 else
        if (a[i]<a[j]) and (b[i]=b[j]) then r:=1 else
        if (a[i]=a[j]) and (b[i]>b[j]) then k:=1 else
        if (a[i]=a[j]) and (b[i]<b[j]) then p:=1;
       if l+r+k+p=4 then inc(ans);
     end;
    writeln(ans);
  end.