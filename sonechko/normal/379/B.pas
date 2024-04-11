var n,m,i,j,k,ans,l,r:Longint;
    a:array[1..300]of longint;
    s:ansistring;
  begin
    read(n);
    for i:=1 to n do
     read(a[i]);
    l:=1;
    for i:=1 to n do
     while a[i]>0 do
      begin
        while l<>i do
         if l>i then begin dec(l); write('L'); end else begin inc(l); write('R'); end;
        write('P');
        dec(a[i]);
        if i<n then begin inc(l); write('R'); end else begin dec(l); write('L'); end;
        if a[l]<>0 then begin dec(a[l]); write('P'); end;
          if i<n then begin dec(l); write('L'); end else begin inc(l); write('R'); end;
      end;
    writeln;
  end.