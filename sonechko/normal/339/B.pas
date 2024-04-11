var n,m,i,j,k,l,r:longint;
    ans:int64;
  begin
    read(n,m);
    l:=1;
    for i:=1 to m do
     begin
       read(r);
       if l<=r then ans:=ans+r-l else ans:=ans+((n+1)-l)+(r-1);
       l:=r;
     end;
    writeln(ans);
  end.