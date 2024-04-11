var n,m,i,j,k,ans,l,r:int64;
  begin
    read(n,m);
    r:=1;
    while r<m do
     begin
       r:=r*n;
       inc(ans);
     end;
    if r<>m then writeln('NO') else
     begin writeln('YES'); writeln(ans-1); end;
  end.