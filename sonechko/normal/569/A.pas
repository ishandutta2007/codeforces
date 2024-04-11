var n,m,i,j,k,ans,l,r:longint;
  begin
    read(n,m,k);
    r:=m;
    l:=1;
    ans:=1;
    while l<=n do
     begin
       r:=r+k-1;
       l:=l+k;
       if (l>r) and (l<=n) then begin inc(ans); l:=1; end;
     end;
    writeln(ans);
  end.