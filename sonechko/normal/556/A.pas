var n,m,i,j,k,ans,l,r:longint;
    s,t:ansistring;
  begin
    readln(n);
    readln(s);
    t:='';
    for i:=1 to length(s) do
     if (t='') or (s[i]=t[length(t)]) then t:=t+s[i] else delete(t,length(t),1);
    writeln(length(t));
  end.