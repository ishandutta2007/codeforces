var s,s1:ansistring;
    i,j,k,l,r:longint;
  begin
    readln(s);
    k:=0;
    for i:=1 to length(s) div 2 do
     if s[i]<>s[length(s)-i+1] then k:=1;
    for i:=1 to length(s) do
     if s[i] in ['B'..'G','J'..'L','N','P'..'S','Z'] then k:=1;
    if k=0 then writeln('YES') else writeln('NO');
  end.