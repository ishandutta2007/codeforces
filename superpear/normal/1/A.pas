var m,n,a:longint;
begin
  readln(m,n,a);
  writeln(int64((m-1) div a+1)*((n-1) div a+1));
end.