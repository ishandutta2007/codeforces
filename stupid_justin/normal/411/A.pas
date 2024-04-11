var s:ansistring;
    i,a,b,c:longint;
begin
  read(s);
  for i:=1 to length(s) do
    begin
      if (s[i]>='0')and(s[i]<='9') then a:=1;
      if (s[i]>='a')and(s[i]<='z') then b:=1;
      if (s[i]>='A')and(s[i]<='Z') then c:=1;
    end;
  if (a=1)and(b=1)and(c=1)and(length(s)>=5) then write('Correct') else write('Too weak');//
end.