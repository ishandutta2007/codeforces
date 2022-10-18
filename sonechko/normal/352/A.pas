var n,m,i,j,k,l,r,ans:longint;
  begin
    read(n);
    l:=0;
    r:=0;
    for i:=1 to n do
     begin
       read(k);
       if k=0 then inc(r) else inc(l);
     end;
    if (r=0) then write(-1) else
    if (l<9) and (r>0) then write(0) else
    if (l<9) and (r=0) then write(-1) else

     begin
       for i:=1 to (l div 9)*9 do
        write('5');
       for i:=1 to r do
        write('0');
     end;

    writeln();
  end.