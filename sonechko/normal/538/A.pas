var s,t:ansistring;
    i,j,k,ans,l,r,n,m:longint;
  begin
    readln(s);
    if s='CODEFORCES' then begin writeln('YES'); halt; end;
    for i:=1 to length(s) do
     for j:=1 to length(s)-i+1 do
      begin
        t:=s;
        delete(t,i,j);
        if t='CODEFORCES' then begin writeln('YES'); halt; end;
      end;
    writeln('NO');
  end.