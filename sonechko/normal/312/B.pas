var a,b,c,d,x,y,l,r,z:extended;
    i:longint;
  begin
    read(a,b,c,d);
    y:=0;
    z:=0;
    x:=1;
    l:=a/b;
    r:=c/d;
    for i:=1 to 100000 do
     begin
       y:=y+(x*l);
       z:=z+(x*r);
       x:=x*(1-l)*(1-r);
     end;
    writeln(y:0:6);
  end.