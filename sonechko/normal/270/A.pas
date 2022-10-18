Var n,i,l:longint;
  Begin
    Read(n);
    for i:=1 to n do
     begin
       Read(l);
       if frac(360/(180-l))=0 then writeln('YES') else writeln('NO');
     end;
  End.