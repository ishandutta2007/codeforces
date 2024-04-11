var n,m,k:longint;
  begin
    read(n,m,k);
    n:=n-m;
    if n>k then n:=n-(n-(k+1));
    writeln(n);
  end.