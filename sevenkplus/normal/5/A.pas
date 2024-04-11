program A_;
var s:string[100];
    k,a:longint;
begin
  k:=0;a:=0;
  while not eof do
    begin
      readln(s);
      if s[1]='+' then inc(k) else
      if s[1]='-' then dec(k) else
        inc(a,k*(length(s)-pos(':',s)));
    end;
  writeln(a);
end.