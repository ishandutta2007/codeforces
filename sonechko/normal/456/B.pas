var n,m,i,j,k,l,r,p:Longint;
    s:ansistring;
  begin
    readln(s);
    r:=0;
    for i:=1 to length(s) do
     begin
       val(s[i],l,p);
       l:=r*10+l;
       r:=l mod 4;
     end;
    if r=0 then writeln('4') else writeln('0');
  end.