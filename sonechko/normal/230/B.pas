var n,m,i,j,r:longint; l,k:int64;
  begin
    read(n);
    for j:=1 to n do
     begin
       read(l);
       if l=1 then writeln('NO') else
       if frac(sqrt(l))<>0 then writeln('NO') else
        begin
          r:=round(sqrt(l));
          k:=0;
          for i:=2 to round(sqrt(r)) do
           if r mod i=0 then begin K:=1; break; end;
          if (k=0) then writeln('YES') else writeln('NO');
        end;
     end;
  end.