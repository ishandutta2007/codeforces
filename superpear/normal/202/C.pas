var ans,n,i,sc,sd,n1,cu:longint;
begin
  readln(n);
  if n=1 then
    begin
      writeln(1);
      halt;
    end;
  if n=2 then
    begin
      writeln(3);
      halt;
    end;
  for ans:=2 to n*10 do
    begin
      sd:=(ans+1) div 2-1;
      sc:=(sd*sd+1) div 2;
      if (ans mod 2=0) and (n mod 4=0) then
        begin
          if sc*4>=n then
            begin
              writeln(ans);
              halt;
            end;
        end
      else
        if ans mod 2=1 then
          begin
            n1:=n;
            if n1>=sc*4 then dec(n1,sc*4) else n1:=n1 mod 4;
            cu:=(sd div 2)*4+1;
            if cu>=n1 then
              begin
                writeln(ans);
                halt;
              end;
          end;
    end;
end.