var n,m,k,l,r:int64;
    i,j:longint;
  begin
    read(n);
    for i:=1 to n-1 do
     begin
       l:=l+(n-i)*i;
     end;
    writeln(l+n);
  end.