var s,t:ansistring;
    i,j,k,l,n:longint;
  begin
    readln(s);
    t:='';
    for i:=1 to length(s) do
     if s[i] in ['A'..'Z'] then s[i]:=chr(ord(s[i])+32);
    for i:=1 to length(s) do
     if not(s[i] in ['a','o','y','e','u','i']) then t:=t+'.'+s[i];
    writeln(t);
  end.