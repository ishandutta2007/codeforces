const xx:array[1..8] of longint=(-2,-1,1,2,-2,-1,1,2);
      yy:array[1..8] of longint=(-1,-2,2,1,1,2,-2,-1);
var x1,y1,x2,y2,x3,y3,s,d:longint;
    c1,c2:char;
    f:boolean;
begin
  readln(c1,c2);
  x1:=ord(c1)-ord('a')+1;y1:=ord(c2)-ord('0');
  readln(c1,c2);
  x2:=ord(c1)-ord('a')+1;y2:=ord(c2)-ord('0');
  s:=0;
  for x3:=1 to 8 do
    for y3:=1 to 8 do
      begin
        f:=true;
        if (x3=x1) and (y3=y1) then f:=false;
        if (x3=x2) and (y3=y2) then f:=false;
        if (x1=x2) or (y1=y2) or (x1=x3) or (y1=y3) then f:=false;
        for d:=1 to 8 do
          if (x2+xx[d]=x3) and (y2+yy[d]=y3) then f:=false;
        for d:=1 to 8 do
          if (x3+xx[d]=x2) and (y3+yy[d]=y2) then f:=false;
        for d:=1 to 8 do
          if (x2+xx[d]=x1) and (y2+yy[d]=y1) then f:=false;
        for d:=1 to 8 do
          if (x3+xx[d]=x1) and (y3+yy[d]=y1) then f:=false;
        if f then inc(s);
      end;
  writeln(s);
end.