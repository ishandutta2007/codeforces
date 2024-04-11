var n,i,j,k,l,r:longint;
  begin
    read(n);
    for i:=1 to n do
     begin
       read(l,r,j);
       if l+r+j>=2 then inc(k);

     end;
    writeln(k);
  end.