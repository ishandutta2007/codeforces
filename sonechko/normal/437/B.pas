var a,b:array[1..100000]of longint;
    i,j,k,l,r,n,m:longint;
  begin
    read(n,m);
    for i:=m downto 1 do
     begin
       if i mod 2=1 then a[i]:=1 else
       begin
         k:=1;
         j:=i;
         while j>0 do
          if j mod 2=0 then begin k:=k*2;  j:=j div 2; end else
          begin break; end;
         a[i]:=k;
       end;
     end;
    l:=0;
    for i:=m downto 1 do
     if a[i]<=n then begin inc(l); b[l]:=i; n:=n-a[i]; end;
    if n<>0 then begin writeln('-1'); halt; end;
    writeln(l);
    for I:=1 to l do
     write(b[i],' ');
    writeln;
  end.