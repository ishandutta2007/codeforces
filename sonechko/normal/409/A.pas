var s,s1,t,t1:STRING;
    k1,i,j,k:longint;
  begin
    readln(s);
    readln(s1);
    k:=0;
    k1:=0;
    for i:=1 to length(s) do
     if i mod 2=1 then
      begin
        t:=s[i]+s[i+1];
        t1:=s1[i]+s1[i+1];
        if (t='[]') and (t1='()') then inc(k);
        if (t='[]') and (t1='8<') then inc(k1);
        if (t='()') and (t1='[]') then inc(k1);
        if (t='()') and (t1='8<') then inc(k);
        if (t='8<') and (t1='[]') then inc(k);
        if (t='8<') and (t1='()') then inc(k1);
      end;
    if k=k1 then writeln('TIE') else
    if k>k1 then writeln('TEAM 1 WINS') else
    writeln('TEAM 2 WINS');
  end.