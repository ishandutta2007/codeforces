var n,m,i,j,k,l,r:longint;
  begin
    read(n);
    for i:=1 to n do
     begin
       read(m);
       l:=l+m;
     end;
    if l mod n=0 then writELN(n) else writeln(n-1);
  end.