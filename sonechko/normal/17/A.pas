var n,m,i,j,k,l,r,ans:longint;
    a:array[1..1000]of longint;
  begin
    read(n,r);
    m:=0;
    for i:=2 to n do
     begin
       l:=0;
       for j:=2 to round(sqrt(i)) do
        if i mod j=0 then begin l:=1; break; end;
       if l=0 then begin inc(m); a[m]:=i; end;
     end;
    for i:=1 to m do
     for j:=2 to i-1 do
      if a[j]+a[j-1]+1=a[i] then begin inc(ans); break; end;
    if ans>=r then writeln('YES') else writeln('NO');
  end.