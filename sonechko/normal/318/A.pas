var n,m,i,j,k,l,r:int64;
  begin
    read(n,m);
    if ((n mod 2=0) and (m<=n div 2))
    or ((n mod 2=1) and (m<=n div 2+1)) then k:=1 else k:=2;
    if (k=1) then writeln(m*2-1) else writeln((m-(n+1) div 2)*2);
 
  end.