var s,t:ansistring;
    i,j,k,ans,l,r,n,m:longint;
  begin
    readln(s);
    for i:=1 to length(s) do
     if s[i]='(' then t:=t+s[i] else
     if s[i]='{' then t:=t+s[i] else
     if s[i]='<' then t:=t+s[i] else
     if s[i]='[' then t:=t+s[i] else
     if (length(t)=0) then begin writeln('Impossible'); halt; end else
     if (s[i]=')') and (t[length(t)]='(')
     then delete(t,length(t),1) else
     if (s[i]='>') and (t[length(t)]='<')
     then delete(t,length(t),1) else
     if (s[i]='}') and (t[length(t)]='{')
     then delete(t,length(t),1) else
     if (s[i]=']') and (t[length(t)]='[')
     then delete(t,length(t),1) else
      begin delete(t,length(t),1); inc(ans); end;
    if length(t)<>0 then writeln('Impossible') else writeln(ans);
  end.