var n,m,i,j,k,l,r:Longint;
  begin
    read(n,m);
    for i:=1 to n do
     begin
       read(r);
       if i<>1 then
        begin
         if l-r-m>k then k:=l-r-m;
        end;
       l:=r;
     end;
    writeln(k);
  end.