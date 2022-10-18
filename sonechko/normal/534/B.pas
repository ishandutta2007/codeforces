var n,m,i,j,k,ans,l,r:longint;
    a:array[1..100]of longint;
  begin
    read(a[1],k,n,r);
    a[n]:=k;
    for i:=2 to n-1 do
     a[i]:=a[i-1]+r;
    for i:=n-1 downto 2 do
     if a[i+1]+r<a[i] then a[i]:=a[i+1]+r else break;
    for i:=1 to n do
     ans:=ans+a[i];
    writeln(ans);
  end.