var k,b,n,t,c,i:longint;
    s:int64;
begin
  readln(k,b,n,t);
  s:=1;
  c:=n+1;
  for i:=1 to n do
    begin
      s:=int64(s)*k+b;
      if s>t then
        begin
          c:=i;
          break;
        end;
    end;
  writeln(n-c+1);
end.