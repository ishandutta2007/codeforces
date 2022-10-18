var n,m,i,j,k,ans,l,r:longint;
    t:string;
  begin
    readln(n);
    readln(t);
    for i:=1 to n do
     if t[i] in ['4','7'] then inc(l);
    if l<>n then begin writeln('NO'); halt; end;
    l:=0;
    r:=0;
    for i:=1 to n do
     begin
       val(t[i],k,j);
       if i<=n div 2 then l:=l+k else r:=r+k;
     end;
    if l=r then writeln('YES') else writeln('NO');
  end.