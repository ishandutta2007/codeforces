var n,m,i,j,k,ans,l,r,p:longint;
  begin
    read(n,m);
    p:=maxlongint;
    for i:=1 to n do
     begin
      read(k);
      if k>l then l:=k;
      if k*2<p then p:=k*2;
     end;
    if p>l then l:=p;
    r:=maxlongint;
    for i:=1 to m do
     begin
       read(k);
       if k<r then r:=k;
     end;
    if l>=r then writeln(-1) else writeln(l);
  end.