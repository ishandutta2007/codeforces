var n,m,i,j,k,ans,l,r:longint;
  begin
    read(n);
    for i:=1 to n do
     begin
       read(k);
       if k mod 2=0 then inc(l) else inc(r);
     end;
    if r mod 2=0 then writeln(l) else writeln(r);
  end.