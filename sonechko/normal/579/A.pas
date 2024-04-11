var n,m,i,j,k,ans,l,r:Longint;
  begin
    read(n);
    l:=0;
    ans:=1;
    while (n>1) do
     begin
       //if (n mod 2=0) and (l<>2) then begin inc(ans); l:=2; end;
       if n mod 2=0 then n:=n div 2 else begin inc(ans); n:=n-1; end;
     end;
    writeln(ans);
  end.