var a:array[1..3,1..3]of char;
    i,j,l,r,n,m,k,ans:longint;
  begin
    readln(a[1,1],a[1,2],a[1,3]);
    readln(a[2,1],a[2,2],a[2,3]);
    readln(a[3,1],a[3,2],a[3,3]);
    if (a[1,1]=a[3,3]) and (a[1,2]=a[3,2]) and (a[1,3]=a[3,1]) and (a[2,1]=a[2,3])
    then writeln('YES') else writeln('NO');
  end.