var n,m,i,j,k,ans,l,r:int64;
  begin
    read(n,m,k);
    n:=abs(n);
    m:=abs(m);
    l:=(n+m) mod 2;
    r:=k mod 2;
    if (l<>r) or (k<(n+m)) then writeln('No') else writeln('Yes');
  end.