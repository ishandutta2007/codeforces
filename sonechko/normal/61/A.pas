var s,t:ansistring;
    i:longint;
  begin
    readln(s);
    readln(t);
    for i:=1 to length(s) do
     if s[i]=t[i] then t[i]:='0' else t[i]:='1';
    writeln(t);
  end.