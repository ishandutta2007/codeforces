uses math;
var x1,y1,x2,y2,l,r,ans:longint;
  begin
    read(x1,y1,x2,y2);
    l:=abs(x1-x2);
    r:=abs(y1-y2);
    ans:=max(l,r);
    writeln(ans);
  end.