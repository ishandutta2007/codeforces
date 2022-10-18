var n,m,i,x2,x1,y1,y2:longint;
    ans:extended;
  begin
    read(n,m);
    for i:=1 to n do
     begin
       read(x2,y2);
       if i=1 then begin x1:=x2; y1:=y2; end;
       ans:=ans+sqrt(sqr(x1-x2)+sqr(y1-y2));
       x1:=x2;
       y1:=y2;
     end;
    writeln(ans/50*m:0:6);
  end.