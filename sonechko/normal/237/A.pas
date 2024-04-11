var n,m,i,j,k,ans,l,r:longint;
    a,b:array[1..100000]of longint;
  begin
    read(n);
    ans:=0;
    l:=1;
    for i:=1 to n do
     read(a[i],b[i]);
    for i:=2 to n do
     if (a[i]=a[i-1]) and (b[i]=b[i-1]) then inc(l) else
     if l>ans then begin ans:=l; l:=1; end else l:=1;
    if l>ans then ans:=l;
    writeln(ans);
  end.