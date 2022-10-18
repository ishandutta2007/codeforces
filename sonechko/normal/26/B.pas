var s,t:ansistring;
    i,j,k,ans,l,r:longint;
  begin
    readln(s);
    t:='';
    for i:=1 to length(s) do
     if s[i]='(' then begin t:=t+s[i]; inc(l); end else
     if (s[i]=')') and (l>0) then begin t:=t+s[i]; dec(l); end;
    writeln(length(t)-l);
  end.