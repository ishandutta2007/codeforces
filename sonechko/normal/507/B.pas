var r,x1,y1,x2,y2:extended; p:extended;
  begin
    read(r,x1,y1,x2,y2);
    p:=sqrt(sqr(x1-x2)+sqr(y1-y2))/(r+r);
    if frac(p)=0 then writeln(p:0:0) else writeln(trunc(p)+1);
  end.