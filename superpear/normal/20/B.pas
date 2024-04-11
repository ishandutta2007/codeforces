var a,b,c,delta,c1,c2:extended;
begin
  readln(a,b,c);
  if a=0 then
    begin
      if b=0 then
        begin
          if c=0 then writeln('-1') else writeln('0');
        end
      else
        begin
          writeln(1);
          writeln(-c/b:0:10);
        end;
    end
  else
    begin
      delta:=b*b-4*a*c;
      if abs(delta)<=1e-9 then
        begin
          writeln(1);
          writeln(-b/(2*a):0:10);
        end
      else
        if delta<0 then writeln(0) else
          begin
            writeln(2);
            c1:=(-b-sqrt(delta))/(2*a);
            c2:=(-b+sqrt(delta))/(2*a);
            if c1>c2 then
              begin
                writeln(c2:0:10);
                writeln(c1:0:10);
              end
            else
              begin
                writeln(c1:0:10);
                writeln(c2:0:10);
              end;
          end;
    end;
end.