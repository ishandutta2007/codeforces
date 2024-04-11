var n,m,k,ans,l,r:int64;
    i,j:longint;
    a,b:array[1..1000]of int64;
  begin
    read(n);
    for i:=1 to n do
     read(a[i]);
    for i:=1 to n do
     read(b[i]);
    for i:=1 to n do
     begin
        l:=0;
        r:=0;
        for j:=i to n do
         begin
           l:=l or a[j];
           r:=r or b[j];
           if (l+r>ans) then ans:=l+r;
         end;
     end;
    writeln(ans);
  end.