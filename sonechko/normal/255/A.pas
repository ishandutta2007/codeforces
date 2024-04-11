var n,m,i,j,k,l,r:longint;
  begin
    read(n);
    for i:=1 to n do
     begin
       read(m);
       if i mod 3=1 then inc(l,m) else
       if i mod 3=2 then inc(r,m) else inc(k,m);
     end;
    if (l>=r) and (l>=k) then writeln('chest') else
    if (r>=k) and (r>=l) then writeln('biceps') else
    writeln('back');
  end.