var n,m,i,j,k,ans,l,r:longint;
    s,t:ansistring;
    a:array['a'..'z']of longint;
  begin
    readln(n);
    readln(s);
    for i:=1 to length(s) do
     begin
       inc(a[s[i]]);
       if a[s[i]]=1 then inc(l);
     end;
    if l<n then begin writeln('NO'); halt; end;
    fillchar(a,sizeof(a),0);
    t:='';
    writeln('YES');
    for i:=1 to length(s) do
     begin
       inc(a[s[i]]);
       if (a[s[i]]=1) and (n>0) then
        begin
          if t<>'' then writeln(t);
          t:='';
          dec(n);
        end;
       t:=t+s[i];
     end;
    writeln(t);
  end.