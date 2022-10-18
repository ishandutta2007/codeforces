uses math;
Var n,m,i,j,k,ans,l,r:longint;
    a:array[0..100001]of int64;
   begin
    read(n);
    for i:=1 to n do
     read(a[i]);
    a[0]:=-1000000000000000000;
    a[n+1]:=1000000000000000000;
    for i:=1 to n do
     writeln(min(abs(a[i]-a[i-1]),abs(a[i+1]-a[i])),' ',max(abs(a[i]-a[1]),abs(a[n]-a[i])))


  end.