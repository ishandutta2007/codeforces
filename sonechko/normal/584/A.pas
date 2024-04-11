var n,m,i,j,k,ans,l,r:longint;
    s:ansistring;
  begin
    read(n,m);
    if (n=1) and (m=10) then write('-1') else
    if m=10 then
     begin
       for i:=1 to n-1 do
        write('1');
       write('0');
     end else
    for i:=1 to n do
     write(m);
    writeln;
  end.