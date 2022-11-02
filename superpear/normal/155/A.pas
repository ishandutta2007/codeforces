var n,i,max,min,ans,xc:longint;
begin
  readln(n);
  read(xc);
  ans:=0;
  max:=xc;
  min:=xc;
  for i:=1 to n-1 do
    begin
      read(xc);
      if xc>max then
        begin
          inc(ans);
          max:=xc;
        end;
      if xc<min then
        begin
          inc(ans);
          min:=xc;
        end;
    end;
  writeln(ans);
end.