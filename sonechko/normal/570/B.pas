var n,m,i,j,k,ans,l,r:longint;
  begin
    read(n,m);
    if n=1 then writeln(1) else
    if m>n div 2 then writeln(m-1) else writeln(m+1);
  end.