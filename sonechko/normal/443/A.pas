var n,i,j,k,l,r:longint;
    s:ansistring;
    m:set of 'a'..'z';
  begin
    readln(s);
    m:=[];
    for i:=1 to length(s) do
     if (s[i] in ['a'..'z']) and not(s[i] in m) then begin inc(l); m:=m+[s[i]]; end;
     writeln(l);
  end.