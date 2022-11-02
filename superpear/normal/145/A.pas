var s1,s2:ansistring;
    n,i,u,v:longint;
begin
  readln(s1);
  readln(s2);
  n:=length(s1);
  u:=0;
  v:=0;
  for i:=1 to n do
    begin
      if (s1[i]='4') and (s2[i]='7') then inc(u);
      if (s1[i]='7') and (s2[i]='4') then inc(v);
    end;
  if u>v then writeln(u) else writeln(v);
end.