var s,n,m,l,r,k:int64;
  begin
    read(n,m,l,r,k);
    s:=n+m+l+r+k;
    if (s mod 5=0) and (s<>0) then writeln(s div 5) else writeln(-1);
  end.