var s1,s2:string;
    n,c,i:longint;
    ch1,ch2:char;
begin
  readln(s1);
  readln(s2);
  n:=length(s1);
  c:=0;
  for i:=1 to n do
    begin
      if (s1[i]>='a') and (s1[i]<='z') then
        ch1:=chr(ord(s1[i])-32)
      else
        ch1:=s1[i];
      if (s2[i]>='a') and (s2[i]<='z') then
        ch2:=chr(ord(s2[i])-32)
      else
        ch2:=s2[i];
      s1[i]:=ch1;s2[i]:=ch2;
    end;
  if s1=s2 then writeln(0) else
    if s1<s2 then writeln(-1) else
      if s1>s2 then writeln(1);
end.