var n,m,i,j,k,ans,l,r:longint;
    s,t,d:string;
    h:char;
  begin
    readln(n);readln(s);
    for i:=1 to n do
     for j:=i+1 to n do
      if s[i]>s[j] then begin h:=s[i]; s[i]:=s[j]; s[j]:=h; end;
    for i:=n+1 to 2*n do
     for j:=i+1 to 2*n do
       if s[i]>s[j] then begin h:=s[i]; s[i]:=s[j]; s[j]:=h; end;
    t:=copy(s,1,n);
    d:=copy(s,n+1,n*2);
    for i:=1 to n do
     if t[i]<d[i] then l:=l+1 else
     if t[i]>d[i] then r:=r+1;
    if (l=n) or (r=n) then writeln('YES') else writeln('NO');
  end.