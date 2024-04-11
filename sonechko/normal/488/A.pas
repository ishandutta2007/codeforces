var n,m,i,j,k,l,r:Longint;
  begin
    read(n);
    if i>=0 then
    for i:=n+1 to n+10000000 do
     begin
       k:=abs(i);
       l:=0;

       while k>0 do
        begin
          if k mod 10=8 then begin l:=1; break; end;
          k:=k div 10;
        end;

       if l=1 then begin writeln(i-n); halt; end;
     end;

  end.