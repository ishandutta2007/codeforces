var n,m,i,j,k,l,r:longint;
  begin
    read(n,m);
    for I:=1 to n do
     begin
       read(l);
       r:=r+l;
     end;
    if r+(n-1)*10>m then writeln(-1) else
    begin
      m:=m-r;
      writeln(m div 5);
    end;
  end.