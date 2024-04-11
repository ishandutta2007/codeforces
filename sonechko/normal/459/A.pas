var x1,x2,y1,y2:longint;
  begin
    read(x1,y1,x2,y2);
    if (x1=x2) then
     begin
      writeln(x1+abs(y2-y1),' ',y1,' ',x2+abs(y2-y1),' ',y2);
      halt;
     end;
    if (y1=y2) then
     begin
      write(x1,' ',y1+abs(x2-x1),' ',x2,' ',y2+abs(x2-x1));
      halt;
     end;
    if (abs(x2-x1)<>abs(y2-y1)) then begin write(-1); halt; end;
   write(x1,' ',y2,' ',x2,' ',y1)
  end.