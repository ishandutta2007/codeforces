var n,m,i,j,l:longint;
    s:string;
  begin
    readln(n);
    for i:=1 to n do
     begin
       readln(s);
       if pos('+',s)<>0 then inc(l) else dec(l);
     end;
    writeln(l);
  end.