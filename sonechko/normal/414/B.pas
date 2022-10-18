var n,m,i,j,k,ans,l,r:longint;
    a:array[1..2000,1..2000]of longint;
  begin
    read(n,m);
    for i:=1 to n do
     a[1,i]:=1;
    for i:=2 to m do
     for j:=1 to n do
      for l:=1 to 2000 do
       if l*j>n then break else a[i,j*l]:=(a[i,j*l]+a[i-1,j]) mod 1000000007;
    for i:=1 to n do
     ans:=(ans+a[m,i]) mod 1000000007;
    writeln(ans);
  end.