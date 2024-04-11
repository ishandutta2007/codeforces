var s,t:ansistring;
    a:array[0..200000]of int64;
    k,ans,l,r,n,m:int64;
    i,j:longint;
  begin
    read(l);
    if l mod 2=1 then writeln(0) else
    if l mod 4=0 then writeln(l div 4-1) else writeln(l div 4);
  end.