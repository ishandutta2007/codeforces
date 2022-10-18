var n,m:longint;
  begin
    read(n,m);
    if n<m then n:=n else n:=m;
    if n mod 2=0 then writeln('Malvika') else writeln('Akshat');
  end.