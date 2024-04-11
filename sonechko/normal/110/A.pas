var s,t:string;
    i,j,k,l,r,m:longint;
  begin
    readln(s);
    m:=0;
    for i:=1 to length(s) do
     if (s[i] in ['4','7']) then inc(m);
    str(m,s);
    for i:=1 to length(s) do
     if not(s[i] in ['4','7']) then begin writeln('NO'); halt; end;
    writeln('YES');
  end.