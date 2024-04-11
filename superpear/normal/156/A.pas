var st,s1:ansistring;
    s,sc:array[0..5000] of char;
    ls,lsc,i,min,e1,e2,nowans:longint;
begin
  readln(st);
  for i:=1 to 2000 do st:=' '+st;
  ls:=length(st);
  for i:=1 to ls do s[i]:=st[i];
  readln(s1);
  lsc:=length(s1);
  for i:=1 to lsc do sc[i]:=s1[i];
  min:=maxlongint;
  for i:=1 to ls do
    begin
      e1:=i;
      e2:=1;
      nowans:=0;
      while (e1<=ls) and (e2<=lsc) do
        begin
          if s[e1]<>sc[e2] then inc(nowans);
          inc(e1);
          inc(e2);
        end;
      nowans:=nowans+(lsc-e2+1);
      if nowans<min then min:=nowans;
    end;
  writeln(min);
end.