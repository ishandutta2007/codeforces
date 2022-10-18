var n,m,i,j,k,ans,l,r:longint;
  begin
    read(n);
    for i:=1 to n do
     begin
       read(l,r,m,k);
       ans:=ans+((m-l+1)*(k-r+1));
     end;
    writeln(ans);
  end.