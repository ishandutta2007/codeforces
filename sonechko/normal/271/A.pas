var n,m,i,j,k,l,r:longint;
  begin
    read(n);
    for i:=n+1 to 10000 do
     begin
       k:=i mod 10;
       l:=i div 10 mod 10;
       r:=i div 100 mod 10;
       j:=i div 1000;
       if (k<>l) and (k<>r) and (k<>j)
       and(l<>r) and (l<>j) and (r<>j) then begin writeln(i); halt; end;
     end;
  end.