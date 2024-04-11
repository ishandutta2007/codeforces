var ls,ls1,i,e:longint;
    s,s1:string;
    flag:boolean;
begin
  readln(s);
  ls:=length(s);
  e:=0;
  for i:=1 to ls do
    if (s[i]='4') or (s[i]='7') then inc(e);
  str(e,s1);
  ls1:=length(s1);
  flag:=true;
  for i:=1 to ls1 do
    if (s1[i]<>'4') and (s1[i]<>'7') then flag:=false;
  if flag then writeln('YES') else writeln('NO');
end.