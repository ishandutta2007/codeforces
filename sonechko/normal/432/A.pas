var n,k,i,j,l,r:longint;
  begin
    read(n,k);
    k:=5-k;
    for i:=1 to n do
     begin
       read(l);
       if l<=k then inc(r);
     end;
    writeln(r div 3);
  end.