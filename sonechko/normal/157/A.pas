var n,m,i,j,k,ans,l,r:longint;
    a:array[1..100,1..100]of longint;
  begin
    read(n);
    for i:=1 to n do
     for j:=1 to n do
      read(a[i,j]);
    for i:=1 to n do
     for j:=1 to n do
      begin
        l:=0;
        r:=0;
        for k:=1 to n do
         l:=l+a[i,k];
        for k:=1 to n do
         r:=r+a[k,j];
        if r>l then inc(ans);
      end;
    writeln(ans);
  end.