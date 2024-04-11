var n,m,i,j,k,l,r:longint;
  begin
    read(n);
    k:=0;
    l:=0;
    for i:=1 to 50 do
     begin
       l:=l+i;
       k:=k+l;
       if (k+(l+i+1))>n then break;
     end;
    writeln(i);
  end.