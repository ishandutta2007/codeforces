var x1,y1,x2,y2,x3,y3,x,y,z,v,w:longint;
procedure good(y1,y2,y3:longint);
 var k:longint;
 begin
   if y1>y2 then begin z:=y1;y1:=y2;y2:=z; k:=1;end else k:=0;

      if (y3>=y2) or (y3<=y1) then begin writeln(2); halt; end;
      if k=1 then begin z:=y1;y1:=y2;y2:=z; end;
 end;
  begin
    read(x1,y1,x2,y2,x3,y3);
    if (x1=x2) and (x2=x3) then begin writeln(1); halt; end;
    if (y1=y2) and (y2=y3) then begin writeln(1); halt; end;
    if (x1=x2) then good(y1,y2,y3);
    if (y1=y2) then good(x1,x2,x3);
    if (x2=x3) then good(y2,y3,y1);
    if (y2=y3) then good(x2,x3,x1);
    if (x1=x3) then good(y1,y3,y2);
    if (y1=y3) then good(x1,x3,x2);

    writeln(3);
  end.