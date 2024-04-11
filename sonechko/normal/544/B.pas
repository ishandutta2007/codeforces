var n,m,i,j,k,ans,l,r:longint;
  begin
    read(n,m);
    if (n*n+1) div 2<m then begin writeln('NO'); halt; end;
    writeln('YES');
    for i:=1 to n do
     begin
       if i mod 2=1 then r:=1 else r:=2;
       for j:=1 to n do
        begin
          if ((r+j) mod 2=0) and (m>0) then begin write('L'); dec(m); end
          else write('S');
        end;
       writeln;
     end;
  end.