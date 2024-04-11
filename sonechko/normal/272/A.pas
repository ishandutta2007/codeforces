var n,m,i,j,k,l,r:longint;
  begin
    read(n);
    m:=0;
    for i:=1 to n do
     begin
       read(l);
       m:=m+l;
     end;
    n:=n+1;
    k:=0;
    for i:=1 to 5 do
     if (m+i)mod n<>1 then inc(k);
    writeln(k);
  end.