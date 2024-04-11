var n,m,i,j,k,ans,l,r:longint;
  begin
    read(n,m);
    for i:=1 to round(sqrt(m)) do
     begin
      if (m mod i=0) and (i<=n) and (m div i<=n) then ans:=ans+2;
      if (i=m div i) and (m mod i=0) and (i<=n) then dec(ans);
     end;
    writeln(ans);
  end.