var s:string;
    flag,ls,i:longint;
begin
  readln(s);
  repeat
    flag:=1;
    ls:=length(s);
    for i:=1 to ls-1 do
      if (s[i]='/') and (s[i+1]='/') then
        begin
          flag:=0;
          delete(s,i,1);
          break;
        end;
  until flag=1;
  if length(s)>1 then
    while s[length(s)]='/' do delete(s,length(s),1);
  writeln(s);
end.