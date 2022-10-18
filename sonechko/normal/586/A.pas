var n,m,i,j,k,ans,l,r:longint;
    a:array[1..101]of longint;
  begin
    read(n);
    for i:=1 to n do
     read(a[i]);
    k:=n;
    for i:=1 to n do
     if a[i]=1 then begin k:=i; break; end;
    l:=0;
    for i:=1 to n do
     if a[i]=1 then l:=i;
    i:=k;
    while i<=l do
     begin
      if a[i]=1 then begin inc(ans); inc(i); end else
      if (a[i]=0) and (a[i+1]=1) then begin inc(ans); inc(i); end else
      begin
        for j:=i+1 to l do
         if a[j]=1 then begin r:=j; break; end;
        i:=r;
      end;
     end;
    writeln(ans);
  end.