var ans:int64;
    f:array[-100..100] of longint;
    sc,i,n:longint;
begin
  readln(n);
  fillchar(f,sizeof(f),0);
  ans:=0;
  for i:=1 to n do
    begin
      read(sc);
      ans:=ans+int64(f[-sc]);
      inc(f[sc]);
    end;
  writeln(ans);
end.