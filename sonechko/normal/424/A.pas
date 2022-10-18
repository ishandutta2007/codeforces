var n,m,i,j,k,l,r,l1,r1:longint;
    s,t:string;
  begin
    readln(n);
    readln(s);
    for i:=1 to length(s) do
     if s[i]='x' then inc(r) else inc(l);
     t:=s;
    for i:=1 to length(s) do
     begin
       if (l>n div 2) and (s[i]='X') then begin dec(l); s[i]:='x'; inc(l1); end;
     end;
    for i:=1 to length(t) do
     begin
       if (r>n div 2) and (t[i]='x') then begin dec(r); t[i]:='X'; inc(r1); end;
     end;
    if ((l1<r1) and (l1<>0)) or (r1=0) then begin writeln(l1); writeln(s) end else
    begin writeln(r1); writeln(t); end;
  end.