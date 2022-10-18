var n,m,i,j,k,ans,l,r,t:Longint;
    a,b:array[1..1000]of longint;
  begin
    read(n);
    for i:=1 to n do
     read(a[i]);
    l:=0;
    r:=0;
    t:=1;
    for i:=1 to n do
     if t=1 then
      begin
        for j:=l+1 to n do
         if (a[j]<=r) and (b[j]=0) then begin b[j]:=1; inc(r); l:=j; break; end;
        if r<>i then
         begin
          inc(ans);
          t:=2;
          for j:=l-1 downto 1 do
           if (a[j]<=r) and (b[j]=0) then begin b[j]:=1; inc(r); l:=j; break; end;
         end;
      end else
      begin
        for j:=l-1 downto 1 do
         if (a[j]<=r) and (b[j]=0) then begin b[j]:=1; inc(r); l:=j; break; end;
        if r<>i then
         begin
           t:=1;
           inc(ans);
           for j:=l+1 to n do
            if (a[j]<=r) and (b[j]=0) then begin b[j]:=1; inc(r); l:=j; break; end;
         end;
      end;
    writeln(ans);
  end.