var i,j,k,ans,l,r,n,m:longint;
  begin
    read(n,m);
    for i:=1 to n do
     for j:=1 to m do
      begin
        read(l,r);
        if l+r>0 then inc(ans);
      end;
    writeln(ans);
  end.