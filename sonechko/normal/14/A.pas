var n,m,i,j,k,ans,l,r,l1,r1:longint;
    a:array[0..51,0..51]of char;
  begin
    readln(n,m);
    for i:=1 to n do
     begin
      for j:=1 to m do
       read(a[i,j]);
      readln;
     end;
    l:=0;
    for i:=1 to n do
     begin
       for j:=1 to m do
        if a[i,j]='*' then begin l:=i; break; end;
       if l<>0 then break;
     end;
    r:=0;
    for j:=1 to m do
     begin
       for i:=1 to n do
        if a[i,j]='*' then begin r:=j; break; end;
       if r<>0 then break;
     end;
    l1:=0;
    for i:=n downto 1 do
     begin
       for j:=m downto 1 do
        if a[i,j]='*' then begin l1:=i; break; end;
       if l1<>0 then break;
     end;
    r1:=0;
    for j:=m downto 1 do
     begin
       for i:=n downto 1 do
        if a[i,j]='*' then begin r1:=j; break; end;
       if r1<>0 then break;
     end;
    for i:=l to l1 do
     begin
      for j:=r to r1 do
       write(a[i,j]);
      writeln;
     end;

  end.