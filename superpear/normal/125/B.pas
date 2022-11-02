var c,s:ansistring;
    ls,t,i,j:longint;

begin
  readln(s);
  ls:=length(s);
  t:=-2;
  c:='';
  for i:=1 to ls do
    if s[i]<>'>' then
      c:=c+s[i]
    else
      begin
        c:=c+s[i];
        if c[2]='/' then
          begin
            for j:=1 to t do write(' ');writeln(c);
            t:=t-2;
          end
        else
          begin
            t:=t+2;
            for j:=1 to t do write(' ');writeln(c);
          end;
        c:='';
      end;
end.