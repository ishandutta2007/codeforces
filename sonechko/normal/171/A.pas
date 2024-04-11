var n,m,i,j,k,ans,l,r:longint;
  begin
    read(n,m);
    while m>0 do
     begin
       l:=l*10+m mod 10;
       m:=m div 10;
     end;
    writeln(l+n);
  end.