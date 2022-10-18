var n,m,i,j,k,ans,l,r:longint;
  begin
    read(n,m);
    while i<=n do
     begin
      if m<i then break else m:=m-i;
      inc(i);
      if i=n+1 then i:=1;
     end;
    writeln(m);
  end.