var n,m,i,j,k,l,r,p:longint;
 function get(x:longint):longint;
  var l:longint;
  s,t:ansistring;
   begin
     str(x,s);
     t:='';
     for i:=1 to length(s) do
      if s[i]<>'0' then t:=t+s[i];
     val(t,l,p);
 
     get:=l;
   end;
  begin
    read(n,m);
    k:=n+m;
    l:=get(n);
    r:=get(m);
    k:=get(k);
    if (l+r=k) then writeln('YES') else writeln('NO');
  end.