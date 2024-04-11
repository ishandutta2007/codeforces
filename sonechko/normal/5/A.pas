var s:string;
    i,j,k,t:Longint;
  begin
    k:=0;
    t:=0;
    while not eof do
     begin
       readln(s);
       if s[1]='+' then inc(K) else
       if s[1]='-' then dec(k) else
       t:=t+k*(length(s)-pos(':',s));
     end;
    writeln(t);
  end.