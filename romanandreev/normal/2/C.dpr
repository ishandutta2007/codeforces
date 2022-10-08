{$APPTYPE CONSOLE}
//{$MODE DELPHI}
{$D+,I+,L+,Q+,R+,S+,O-}
uses
  SysUtils,Math;
type int=longint;
     point=record
       x,y:extended;
     end;
     line=record
       a,b,c:extended;
     end;
const eps=1e-9;
procedure calc(p1,p2:point); forward;
function serper(a,b:point):line;
begin
  result.a:=b.x-a.x;
  result.b:=b.y-a.y;
  result.c:=-(result.a*(a.x+b.x)+result.b*(a.y+b.y))/2;
end;
function dst(a,b:point):extended;
begin
  result:=sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));
end;
function v(a,b:point):point;
begin
  result.x:=b.x-a.x;
  result.y:=b.y-a.y;
end;
procedure l2p(a,b:line);
var dd,dx,dy:extended;
begin
  dd:=a.a*b.b-a.b*b.a;
  dx:=a.c*b.b-a.b*b.c;
  dy:=a.a*b.c-a.c*b.a;
  writeln(-dx/dd:0:5,' ',-dy/dd:0:5);
end;
procedure perCandL(a:point;r:extended;l:line);
var f,ff,ds:extended;
    p,pp,ppp:point;
begin
  ff:=sqrt(l.a*l.a+l.b*l.b);
  if abs(ff)<eps then begin
    halt;
  end;
  l.a:=l.a/ff;
  l.b:=l.b/ff;
  l.c:=l.c/ff;
  ds:=abs(l.a*a.x+l.b*a.y+l.c);
  p.x:=a.x+l.a*ds;
  p.y:=a.y+l.b*ds;
  if abs(p.x*l.a+p.y*l.b+l.c)>eps then begin
    p.x:=a.x-l.a*ds;
    p.y:=a.y-l.b*ds;
  end;
  if abs(ds-r)<eps then begin
    writeln(p.x:0:5,' ',p.y:0:5);
    halt;
  end;
  if ds>r then exit;
  if abs(ds)<eps then begin
    pp.x:=a.x-l.b*r;
    pp.y:=a.y+l.a*r;
    ppp.x:=a.x+l.b*r;
    ppp.y:=a.y-l.a*r;
  end else begin
  f:=sqrt(r*r-ds*ds);
  pp.x:=p.x+v(a,p).y/ds*f;
  pp.y:=p.y-v(a,p).x/ds*f;
  ppp.x:=p.x-v(a,p).y/ds*f;
  ppp.y:=p.y+v(a,p).x/ds*f;
  end;
  calc(pp,ppp);
end;
procedure perCandC(a,b:point;r1,r2:extended);
var l:line;
begin
  l.a:=-2*a.x+2*b.x;
  l.b:=-2*a.y+2*b.y;
  l.c:=-(r1*r1-r2*r2-a.x*a.x-a.y*a.y+b.x*b.x+b.y*b.y);
  if (dst(a,b)<eps)and(abs(r1-r2)<eps) then begin
    halt;
  end;
  if dst(a,b)+r1<r2-eps then begin
    exit;
  end;
  if dst(a,b)+r2<r1-eps then begin
    exit;
  end;
  if dst(a,b)-eps>r1+r2 then begin
    exit;
  end;
  perCandL(a,r1,l);
end;
var a,b,c,c1,c2:point;
    l1,l2:line;
    t1,t2:int;
    r1,r2,r3,f,rc1,rc2,rr1,rr2,rr3:extended;
procedure calc(p1,p2:point);
begin
  if dst(p1,a)<dst(p2,a) then begin
    writeln(p1.x:0:5,' ',p1.y:0:5)
  end else begin
    writeln(p2.x:0:5,' ',p2.y:0:5)
  end;
end;
begin
  //reset(input,'input.txt');
  //rewrite(output,'output.txt');
  read(a.x,a.y,r1);
  read(b.x,b.y,r2);
  read(c.x,c.y,r3);
  if abs(r1-r2)<eps then begin
    t1:=0;
    l1:=serper(a,b);
  end else begin
    rr1:=dst(a,b)/(r1+r2)*r1;
    rr2:=dst(a,b)/(r1+r2)*r2;
    if r1<r2 then begin
      t1:=1;
      rc1:=(rr1+rr1*dst(a,b)/(rr2-rr1))/2;
      f:=rr1-rc1;
      c1.x:=a.x+v(a,b).x/dst(a,b)*f;
      c1.y:=a.y+v(a,b).y/dst(a,b)*f;
    end else begin
      t1:=1;
      rc1:=(rr2+rr2*dst(a,b)/(rr1-rr2))/2;
      f:=rr1+rc1;
      c1.x:=a.x+v(a,b).x/dst(a,b)*f;
      c1.y:=a.y+v(a,b).y/dst(a,b)*f;
    end;
  end;
  if abs(r1-r3)<eps then begin
    t2:=0;
    l2:=serper(a,c);
  end else begin
    rr1:=dst(a,c)/(r1+r3)*r1;
    rr3:=dst(a,c)/(r1+r3)*r3;
    if r1<r3 then begin
      t2:=1;
      rc2:=(rr1+rr1*dst(a,c)/(rr3-rr1))/2;
      f:=rr1-rc2;
      c2.x:=a.x+v(a,c).x/dst(a,c)*f;
      c2.y:=a.y+v(a,c).y/dst(a,c)*f;
    end else begin
      t2:=1;
      rc2:=(rr3+rr3*dst(a,c)/(rr1-rr3))/2;
      f:=rr1+rc2;
      c2.x:=a.x+v(a,c).x/dst(a,c)*f;
      c2.y:=a.y+v(a,c).y/dst(a,c)*f;
    end;
  end;
  if (t1=0)and(t2=0) then begin
    l2p(l1,l2);
  end;
  if (t1=1)and(t2=0) then begin
    perCandL(c1,rc1,l2);
  end;
  if (t1=0)and(t2=1) then begin
    perCandL(c2,rc2,l1);
  end;
  if (t1=1)and(t2=1) then begin
    perCandC(c1,c2,rc1,rc2);
  end;
end.