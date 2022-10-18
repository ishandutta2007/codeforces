uses math;
var a,b,c,d,e:longint;
  begin
    read(a,b,c,d,e);
    writeln(min(a,min(b,min(c div 2,min(d div 7,e div 4)))));
  end.