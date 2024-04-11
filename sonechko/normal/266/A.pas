var n,m,i,j,k,l,r:longint;
    s:ansistring;
  begin
    readln(n);
    readln(s);
    k:=0;
    for i:=2 to length(s) do
     if s[i]=s[i-1] then inc(k);
    writeln(k);
  end.