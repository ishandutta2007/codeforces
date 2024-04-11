var s:ansistring;
    i,n,j,k,l,r,l1,r1,k1,n1:longint;
  begin
    readln(s);
    l:=length(s)-2;
    readln(s);
    r:=length(s)-2;
    readln(s);
    k:=length(s)-2;
    readln(s);
    n:=length(s)-2;
    if ((r*2<=l) and (k*2<=l) and (n*2<=l)) or
       ((l*2<=r) and (l*2<=k) and (l*2<=n)) then l1:=-1;
    if ((l*2<=r) and (k*2<=r) and (n*2<=r)) or
       ((r*2<=l) and (r*2<=k) and (r*2<=n)) then r1:=-1;
    if ((r*2<=k) and (l*2<=k) and (n*2<=k)) or
       ((k*2<=r) and (k*2<=l) and (k*2<=n)) then k1:=-1;
    if ((r*2<=n) and (k*2<=n) and (l*2<=n)) or
       ((n*2<=r) and (n*2<=k) and (n*2<=l)) then n1:=-1;
    if (l1=-1) and (r1<>-1) and (k1<>-1) and (n1<>-1) then writeln('A') else
    if (r1=-1) and (l1<>-1) and (k1<>-1) and (n1<>-1) then writeln('B') else
    if (k1=-1) and (r1<>-1) and (l1<>-1) and (n1<>-1) then writeln('C') else
    if (n1=-1) and (r1<>-1) and (k1<>-1) and (l1<>-1) then writeln('D') else
    writeln('C');
  end.