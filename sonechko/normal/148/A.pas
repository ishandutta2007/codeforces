var n,m,i,j,k,l,r,d:longint;
  begin
    read(k,l,m,n,d);
    r:=d;
    for i:=1 to d do
     if (i mod k<>0) and (i mod l<>0) and (i mod n<>0) and (i mod m<>0) then
      dec(r);
    writeln(r);
  end.