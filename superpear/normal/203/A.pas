var x,t,a,b,da,db,i,j:longint;
begin
  readln(x,t,a,b,da,db);
  for i:=0 to t-1 do
    for j:=0 to t-1 do
      begin
        if (a-i*da+b-j*db=x) then
          begin
            writeln('YES');
            halt;
          end;
        if (a-i*da=x) or (b-j*db=x) or (x=0) then
          begin
            writeln('YES');
            halt;
          end;
      end;
  writeln('NO');
end.