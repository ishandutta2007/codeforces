var s,t:ansistring;
    h:char;
    i,j:Longint;
  begin
    readln(h);
    readln(s);
    t:='qwertyuiopasdfghjkl;zxcvbnm,./    ';
    for i:=1 to length(s) do
     begin
       for j:=1 to length(t) do
        if (s[i]=t[j]) and (h='L') then write(t[j+1]) else
        if (s[i]=t[j]) then write(t[j-1]);
     end;
    writeln;
  end.