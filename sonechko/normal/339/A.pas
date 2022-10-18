var s:ansistring;
    i,j,k,n,m,l,r:longint;
    h:char;
  begin
    readln(s);
    for i:=1 to length(s) do
     if s[i]='1' then inc(l) else
     if s[i]='2' then inc(r) else
     if s[i]='3' then inc(n);
    s:='';
    for i:=1 to l do
     s:=s+'1+';
    for i:=1 to r do
     s:=s+'2+';
    for i:=1 to n do
     s:=s+'3+';
    if s[length(s)]='+' then delete(s,length(s),1);
    writeln(s);
  end.