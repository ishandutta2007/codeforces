var n,m,i,j,k,l,r:longint;
  begin
    read(n);
    k:=1;
    l:=1;
    for j:=1 to n do
     begin
       for i:=1 to (n-k) div 2 do
        write('*');
       for i:=1 to k do
        write('D');
       for i:=1 to (n-k) div 2 do
        write('*');
       WRITELN;
       if k=n then l:=0;
       if (l=1) then inc(k,2) else begin dec(k,2); end;
     end;
  end.