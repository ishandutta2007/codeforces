var n,k,e,i:longint;
    s:string;
begin
  readln(n,k);
  repeat
    n:=n+1;
    e:=0;
    str(n,s);
    for i:=1 to length(s) do
      begin
        if s[i]='4' then e:=e*10+4;
        if s[i]='7' then e:=e*10+7;
      end;
    if e=k then
      begin
        writeln(n);
        halt;
      end;
  until false;
end.