var n,m,j,k,ans,l,r:int64;
    i:longint;
    a:array[1..1000000]of int64;
  begin
    read(n);
    for i:=1 to n do
     read(a[i]);
    ans:=0;
    l:=0;
    for i:=1 to n do
     begin
       ans:=ans+abs(a[i]-l);
       l:=a[i];
     end;
    writeln(ans);
  end.