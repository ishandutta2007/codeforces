uses math;
var n,m,x1,y1,x2,y2:longint;
  begin
    read(n,m,x1,y1,x2,y2);
    if ((x1+x2<=n) and (max(y1,y2)<=m)) or ((x1+x2<=m) and (max(y1,y2)<=n))
    or ((max(x1,x2)<=n) and (y1+y2<=m)) or ((max(x1,x2)<=m) and (y1+y2<=n))
    or ((x1+y2<=n) and (max(x2,y1)<=m)) or ((x1+y2<=m) and (max(x2,y1)<=n))
    or ((max(x1,y2)<=n) and (x2+y1<=m)) or ((max(x1,y2)<=m) and (x2+y1<=n))
     then writeln('YES') else writeln('NO');
  end.