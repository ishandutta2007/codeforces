var n,m,i,j,k,l,r:longint;
  begin
    read(n);
    for i:=1 to n do
     begin
       read(l,r);
       if r-l>=2 then inc(k);
     end;
    writeln(k);
  end.