var n,m,i,c,s,t:longint;
begin
  readln(i);c:=0;s:=0;m:=0;
  for i:=1 to i do
    begin
      read(t);inc(c,t);inc(s,t);if c<0 then c:=0;if m<c then m:=c;
    end;
  writeln(m+m-s);
end.