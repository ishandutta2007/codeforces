var s,t:string;
    i,j,k,l,r:longint;
  begin
    readln(s);
    readln(t);
    for i:=1 to length(s) do
     if s[i]='1' then inc(l);
    for i:=1 to length(t) do
     if t[i]='1' then inc(r);
    if l mod 2<>0 then inc(l);
    if l>=r then writeln('YES') else writeln('NO');
  end.