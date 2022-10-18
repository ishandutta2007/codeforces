var n,m,i,j,k,ans,l,r:longint;
    s,t:ansistring;
  begin
    readln(n,m);
    readln(s);
    readln(t);
    if ((s[1]='<') and (s[n]='>') and (t[1]='v') and (t[m]='^'))
    or ((s[1]='>') and (s[n]='<') and (t[1]='^') and (t[m]='v'))
    then writeln('YES') else writeln('NO');
  end.