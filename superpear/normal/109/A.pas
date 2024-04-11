var n,i,j:longint;
    flag:boolean;
begin
  readln(n);
  flag:=true;
  for i:=0 to n div 4 do
    if flag and ((n-4*i) mod 7=0) then
      begin
        flag:=false;
        for j:=1 to i do write(4);
        for j:=1 to (n-4*i) div 7 do write(7);
        writeln;
      end;
  if flag then writeln(-1);
end.