var s:string;
    ls,flag,i:longint;
begin
  readln(s);
  ls:=length(s);
  flag:=1;
  for i:=2 to ls do
    if (s[i]>='a') and (s[i]<='z') then
      flag:=0;
  if flag=0 then writeln(s) else
    begin
      for i:=1 to ls do
        if (s[i]>='a') and (s[i]<='z') then
          write(chr(ord(s[i])-32))
        else
          write(chr(ord(s[i])+32));
        writeln;
    end;
end.