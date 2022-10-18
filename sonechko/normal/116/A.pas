var n,m,i,j,k,l,r:longint;
  begin
    read(n);
    for i:=1 to n do
     begin
       read(j,k);
       r:=r-j;
       r:=r+k;
       if r>L then l:=r;
     end;
    writeln(l);
  end.