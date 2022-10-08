program A;
var c:array[1..8,1..8] of boolean;
    p:array[1..64,1..5] of longint;
    x1,y1,x2,y2,x,y,xx,yy,cc,f,r,i:longint;
    c1,c2,c3,c4:char;
begin
//  assign(input,'A.in');reset(input);
//  assign(output,'A.out');rewrite(output);
  readln(c1,c2);readln(c3,c4);
  x1:=ord(c1)-ord('a')+1;y1:=ord(c2)-ord('0');
  x2:=ord(c3)-ord('a')+1;y2:=ord(c4)-ord('0');
  fillchar(c,sizeof(c),false);c[x2,y2]:=true;
  fillchar(p,sizeof(p),0);
  f:=1;r:=1;p[1,1]:=x2;p[1,2]:=y2;p[1,3]:=0;p[1,4]:=0;p[1,5]:=0;
  while f<=r do
    begin
      x:=p[f,1];y:=p[f,2];cc:=p[f,5];
      //case 1 U x y+1
      if y<8 then
        begin
          xx:=x;yy:=y+1;
          if not c[xx,yy] then
            begin
              c[xx,yy]:=true;inc(r);
              p[r,1]:=xx;p[r,2]:=yy;p[r,3]:=1;p[r,4]:=f;p[r,5]:=cc+1;
            end;
        end;
      //case 2 D x y-1
      if y>1 then
        begin
          xx:=x;yy:=y-1;
          if not c[xx,yy] then
            begin
              c[xx,yy]:=true;inc(r);
              p[r,1]:=xx;p[r,2]:=yy;p[r,3]:=2;p[r,4]:=f;p[r,5]:=cc+1;
            end;
        end;
      //case 3 L x-1 y
      if x>1 then
        begin
          xx:=x-1;yy:=y;
          if not c[xx,yy] then
            begin
              c[xx,yy]:=true;inc(r);
              p[r,1]:=xx;p[r,2]:=yy;p[r,3]:=3;p[r,4]:=f;p[r,5]:=cc+1;
            end;
        end;
      //case 4 R x+1 y
      if x<8 then
        begin
          xx:=x+1;yy:=y;
          if not c[xx,yy] then
            begin
              c[xx,yy]:=true;inc(r);
              p[r,1]:=xx;p[r,2]:=yy;p[r,3]:=4;p[r,4]:=f;p[r,5]:=cc+1;
            end;
        end;
      //case 5 LU x-1 y+1
      if (x>1) and (y<8) then
        begin
          xx:=x-1;yy:=y+1;
          if not c[xx,yy] then
            begin
              c[xx,yy]:=true;inc(r);
              p[r,1]:=xx;p[r,2]:=yy;p[r,3]:=5;p[r,4]:=f;p[r,5]:=cc+1;
            end;
        end;
      //case 6 LD x-1 y-1
      if (x>1) and (y>1) then
        begin
          xx:=x-1;yy:=y-1;
          if not c[xx,yy] then
            begin
              c[xx,yy]:=true;inc(r);
              p[r,1]:=xx;p[r,2]:=yy;p[r,3]:=6;p[r,4]:=f;p[r,5]:=cc+1;
            end;
        end;
      //case 7 RU x+1 y+1
      if (x<8) and (y<8) then
        begin
          xx:=x+1;yy:=y+1;
          if not c[xx,yy] then
            begin
              c[xx,yy]:=true;inc(r);
              p[r,1]:=xx;p[r,2]:=yy;p[r,3]:=7;p[r,4]:=f;p[r,5]:=cc+1;
            end;
        end;
      //case 8 RD x+1 y-1
      if (x<8) and (y>1) then
        begin
          xx:=x+1;yy:=y-1;
          if not c[xx,yy] then
            begin
              c[xx,yy]:=true;inc(r);
              p[r,1]:=xx;p[r,2]:=yy;p[r,3]:=8;p[r,4]:=f;p[r,5]:=cc+1;
            end;
        end;
      inc(f);
    end;
  for i:=1 to r do
    if (p[i,1]=x1) and (p[i,2]=y1) then break;
  writeln(p[i,5]);
  while i<>1 do
    begin
      case p[i,3] of
        1:writeln('D');
        2:writeln('U');
        3:writeln('R');
        4:writeln('L');
        5:writeln('RD');
        6:writeln('RU');
        7:writeln('LD');
        8:writeln('LU');
      end;
      i:=p[i,4];
    end;
//  close(input);close(output);
end.