uses math;
 var n,m,l,r,k,ans,i,j:longint;
  begin
    read(k,m,n);
    for i:=1 to n do
     ans:=ans+i*k;
    writeln(max(ans-m,0));
  end.