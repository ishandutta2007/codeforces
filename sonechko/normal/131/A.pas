var s,t:string;
    i,l,r:longint;
  begin
    readln(s);
    for i:=1 to length(s) do
     begin
      if (s[i] in ['a'..'z']) and (i<>1) then inc(l);
      if s[i] in ['A'..'Z'] then t:=t+chr(ord(s[i])+32) else t:=t+chr(ord(s[i])-32);
     end;
    if l=0 then writeln(t) else writeln(s);
  end.