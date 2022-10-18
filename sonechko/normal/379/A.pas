var n,m,k,i,j,l,r:longint;
  begin
    read(n,m);
    k:=0;
    l:=0;
    while (n<>0) do
     begin
       n:=n-1;
       l:=l+1;
       k:=k+1;
       if k=m then begin k:=0; n:=n+1; end;
     end;
    if k>=m then
     begin
       k:=k-m;
       l:=l+1;
       k:=k+1;
     end;
    writeln(l);
  end.