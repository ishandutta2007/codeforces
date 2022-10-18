var s,t:ansistring;
    i,j,k,l,r:longint;
  begin
    readln(s);
    readln(t);
    if (length(t)<>length(s)) then writeln('NO')
                                              else
    if s=t then writeln('YES')                else
     begin
       k:=0;
       for i:=1 to length(s) do
        if s[i]='1' then inc(k);
       l:=k;
       k:=0;
       for i:=1 to length(t) do
        if t[i]='1' then inc(k);
       if (l=0) or (k=0) then writeln('NO') else writeln('YES');
     end;
  end.