var i,j,n,m:longint;
    s:ansistring;
  begin
    readln(s);
    if pos('0',s)=0 then delete(s,1,1) else delete(s,pos('0',s),1);
    writeln(s);
  end.