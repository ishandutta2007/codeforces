var s:string;
    a1,a2:longint;
begin
  readln(s);
  val(copy(s,1,2),a1);
  val(copy(s,4,2),a2);
  repeat
    inc(a2);
    if a2=60 then
      begin
        inc(a1);
        a2:=0;
      end;
    if a1=24 then a1:=0;
    if a1 div 10=a2 mod 10 then
      if a2 div 10=a1 mod 10 then
        begin
          if a1<10 then write('0');
          write(a1);
          write(':');
          if a2<10 then write('0');
          writeln(a2);
          halt;
        end;
  until false;
end.