var s,t:ansistring;
    i:longint;
  begin
    readln(s);
    readln(t);
    for i:=1 to length(s) do
     if s[i] in ['a'..'z'] then s[i]:=chr(ord(s[i])-32);
    for i:=1 to length(t) do
     if t[i] in ['a'..'z'] then t[i]:=chr(ord(t[i])-32);
    if s<t then writeln('-1') else
    if s>t then writeln('1') else writeln('0');
  end.