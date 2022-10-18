var n,m,x,y,i,j,k,ans,l,r:longint;
    a,b,c:array[0..1000+1]of longint;
  begin
    read(n,x,y);
    for i:=1 to n do
     read(a[i],b[i]);
    for i:=1 to n do
     if c[i]=0 then
      begin
        inc(ans);
        c[i]:=1;
        l:=y-b[i];
        r:=a[i]-x;
        k:=(x*b[i])-(y*a[i]);
        for j:=1 to n do
         if (c[j]=0) and (a[j]*l+b[j]*r+k=0) then c[j]:=1;
      end;
    writeln(ans);
  end.