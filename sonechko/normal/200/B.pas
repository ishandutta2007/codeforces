var n,m,i,j,k,ans,l,r:longint;
  begin
    read(n);
    for i:=1 to n do
     begin
       read(k);
       l:=l+k;
     end;
    writeln(l/n:0:9);
  end.