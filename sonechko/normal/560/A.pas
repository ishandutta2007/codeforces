var n,m,i,j,k,ans,l,r:longint;
  begin
    read(n);
    r:=1;
    for i:=1 to n do
     begin
       read(l);
       if l=1 then r:=-1;
     end;
    writeln(r);
  end.