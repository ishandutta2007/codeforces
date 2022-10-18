var s:ansistring;
    i,j,k,l,r:longint;
  begin
    readln(s);
    i:=1;
    while i<=length(s) do
     if copy(s,i,3)='WUB' then delete(s,i,3) else break;
    i:=1;
    while i<=length(s) do
     if copy(s,i,3)='WUB' then begin delete(s,i,3); insert(' ',s,i) end
     else inc(i);
    i:=2;
    while i<=length(s) do
     if (s[i]=' ') and (s[i-1]=' ') then delete(s,i,1) else inc(I);
    writeln(s);
  end.