var s:string;
    ls,i:longint;
begin
  readln(s);
  ls:=length(s);
  for i:=1 to ls do
    if (s[i]>='A') and (s[i]<='Z') then s[i]:=chr(ord(s[i])+32);
  for i:=1 to ls do
    if not(s[i] in ['a','e','i','o','u','y']) then
      write('.',s[i]);
  writeln;
end.