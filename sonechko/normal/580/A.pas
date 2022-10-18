var n,m,k,ans,l,r,i,j:longint;
    a:array[1..100000]of longint;
  begin
    read(n);
    for i:=1 to n do
     read(a[i]);
    ans:=0;
    l:=1;
    for i:=2 to n do
     if a[i]>=a[i-1] then inc(l) else begin if l>ans then ans:=l; l:=1; end;
    if l>ans then ans:=l;
    writeln(ans);
  end.