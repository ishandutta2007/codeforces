var n,k,x:longint;
begin
  readln(n);x:=1;
  for k:=1 to n-1 do
    begin
      x:=(x+k-1) mod n+1;
      if k=n-1 then writeln(x) else write(x,' ');
    end;
end.