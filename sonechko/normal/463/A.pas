var n,m,i,j,k,l,r:longint;
  begin
    read(n,m);
    k:=0;
    j:=1;
    for i:=1 to n do
     begin
       read(l,r);
       if (r<>0) then l:=l+1;
       if (l<=m) and (100-r>K) AND (r<>0) then k:=100-r;
       if (l<=m) then j:=0;
     end;
    if j=0 then writeln(k) else writeln('-1');
  end.