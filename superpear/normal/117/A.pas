var m,n,i,x1,y1,z1,e,o:longint;

begin
  readln(n,m);
  for i:=1 to n do
    begin
      readln(x1,y1,z1);
      if x1=y1 then
        writeln(z1)
      else
        begin
          if x1<y1 then
            begin
              e:=z1-(x1-1);
              if e<=0 then o:=0 else o:=(e-1) div (m*2-2)+1;
              writeln(o*(m*2-2)+y1-1);
            end
          else
            begin
              e:=z1-(m*2-1-x1);
              if e<=0 then o:=0 else o:=(e-1) div (m*2-2)+1;
              writeln(o*(m*2-2)+(m*2-1-y1));
            end;
        end;
    end;
end.