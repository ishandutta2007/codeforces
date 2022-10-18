var x,y,n,m,i,j,l,r,k:longint;
  begin
    read(n,m);
    for i:=1 to n do
     begin
       read(x);
       if x>l then l:=x;
       r:=r+x;
     end;
    if r-l>m  then writeln('NO') else writeln('YES');
  end.