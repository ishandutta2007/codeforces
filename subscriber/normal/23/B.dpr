var
 t,i,ans,n:longint;
BEGIN
 readln(t);
 for i:=1 to t do
 begin
  readln(n);
  if n=1 then writeln(0)else writeln(n-2);
 end;
END.