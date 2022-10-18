uses math;
var n,m,i,j,k,ans,l,r:longint;
    a:array[1..100000]of longint;
  begin
    read(n);
    for i:=1 to n do
     read(a[i]);
    l:=a[1];
    r:=a[1];
    k:=1;
    ans:=1;
    for i:=2 to n do
     begin
       if a[i]>l then l:=a[i];
       if a[i]<r then r:=a[i];
       if l-r>1 then
        begin
          ans:=max(ans,(i-1)-k+1);
          if l=a[i] then
           begin
             j:=i;
             while (a[j]<>r) do
              dec(j);
             r:=r+1;
             k:=j+1;
           end else
           begin
             j:=i;
             while (a[j]<>l) do
              dec(j);
             l:=l-1;
             k:=j+1;
           end;
        end;
     end;
    ans:=max(ans,n-k+1);
    writeln(ans);
  end.