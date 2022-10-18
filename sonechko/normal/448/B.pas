var s,t:string;
    a,b:array['a'..'z']of longint;
    i,k,l,r:Longint;
    j:char;
  begin
    readln(s);
    readln(t);
    for i:=1 to length(s) do
     inc(a[s[i]]);
    for i:=1 to length(t) do
     inc(b[t[i]]);
    k:=0;
    for j:='a' to 'z' do
     if b[j]>a[j] then k:=1;
    if k=1 then begin writeln('need tree'); halt; end;
    k:=0;
    for j:='a' to 'z' do
     if a[j]<>b[j] then k:=1;
    if k=0 then begin writeln('array'); halt; end;
    k:=0;
    i:=1;
    l:=1;
    while (l<=length(t)) and (i<=length(s)) do
     if t[l]=s[i] then BEGIN Inc(l); inc(i); end else
                       inc(i);
    if (l>length(t)) then writeln('automaton') ELSE WRITELN('both');
  end.