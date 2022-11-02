var n,y,s,i:longint;
    x:int64;
begin
  readln(n,x,y);
  if y<n then
    writeln(-1)
  else
    begin
      s:=y-(n-1);
      if int64(s)*s+(n-1)>=x then
        begin
          writeln(s);
          for i:=1 to n-1 do writeln(1);
        end
      else
        writeln(-1);
    end;
end.