var s,t,d:ansistring;
    i,j,k,ans,l,r,n,m:longint;
  begin
    readln(s);
    readln(t);
    for i:=1 to length(s) do
     if (s[i]<>t[i]) then inc(l);
    if l mod 2=1 then begin writeln('impossible'); halt; end;
    l:=l div 2;
    for i:=1 to length(s) do
     if s[i]=t[i] then d:=d+s[i] else
     if l>0 then begin d:=d+s[i]; dec(l); end else d:=d+t[i];
    writeln(d);
  end.