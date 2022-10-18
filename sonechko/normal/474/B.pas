var n,m,i,j,p,k,l,r:longint;
    a,b:array[1..100000]of longint;
  begin
    read(n);
    r:=0;
    for i:=1 to n do
     begin
      read(l);
      inc(m);
      a[m]:=r+1;
      r:=r+l;
      b[m]:=r;
     end;
    read(n);
    for j:=1 to n do
     begin
       read(k);
       l:=1;
       r:=m;
       while (r-l>1) do
        begin
          p:=(l+r)div 2;
          if (b[p]<=k) then l:=p else r:=p;
        end;
       if (a[l]<=k) and (k<=b[l]) then writeln(l) else writeln(r);
     end;
  end.