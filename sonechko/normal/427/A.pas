var n,m,i,j,k,l,r:longint;
  begin
    read(n);
    l:=0;r:=0;
    for i:=1 to n do
     begin
       read(m);
       if (m=-1) and (r=0) then inc(l) else
       if (m=-1) then dec(r) else inc(r,m);
     end;
    writeln(l);
  end.