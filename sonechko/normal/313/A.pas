var n,m,i,j,k,l,r:longint;
  begin
    read(n);
    if n>=0 then writeln(n) else
    if n div 10>(n div 100)*10+n mod 10 then writeln(n div 10) else
    writeln((n div 100)*10+n mod 10);
 
  end.