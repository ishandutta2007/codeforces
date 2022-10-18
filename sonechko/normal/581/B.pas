var n,m,i,j,k,ans,l,r:longint;
    a,b:array[1..100000]of longint;
  begin
    read(n);
    for i:=1 to n do
     read(a[i]);
   m:=0;
   for i:=n downto 1 do
    if a[i]>m then m:=a[i] else b[i]:=(m+1)-a[i];
   for i:=1 to n do
    write(b[i],' ');
   writeln;
  end.