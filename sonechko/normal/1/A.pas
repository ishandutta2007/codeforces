var n,m,i,j,k,l,r:int64;
  begin
    read(n,m,k);
    if n mod k=0 then l:=n div k else l:=n div k+1;
    if m mod k=0 then r:=m div k else r:=m div k+1;
    writeln(l*r);
  end.