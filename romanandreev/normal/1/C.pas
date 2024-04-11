program Zc;

{$APPTYPE CONSOLE}
{$MODE DELPHI}
uses
  SysUtils,Math;

type point=record
       x,y:extended;
     end;
     line=record
       a,b,c:extended;
     end;
function serper(a,b:point):line;
begin
  result.a:=b.x-a.x;
  result.b:=b.y-a.y;
  result.c:=-(result.a*(a.x+b.x)/2+result.b*(a.y+b.y)/2);
end;
function l2p(a,b:line):point;
var dd,dx,dy:extended;
begin
  dd:=a.a*b.b-a.b*b.a;
  dx:=a.c*b.b-a.b*b.c;
  dy:=a.a*b.c-a.c*b.a;
  result.x:=-dx/dd;
  result.y:=-dy/dd;
end;
function vp(a,b:point):extended;
begin
  result:=a.x*b.y-a.y*b.x;
end;
function sp(a,b:point):extended;
begin
  result:=a.x*b.x+a.y*b.y;
end;
function dst(a,b:point):extended;
begin
  result:=sqr(a.x-b.x)+sqr(a.y-b.y);
end;
function v(a,b:point):point;
begin
  result.x:=b.x-a.x;
  result.y:=b.y-a.y;
end;
var p1,p2,p3,o:point;
    alp1,alp2,alp0:extended;
    p:integer;
begin
  //reset(input,'input.txt');
  //rewrite(output,'output.txt');
  //writeln(1/sqrt(2):0:10);
  read(p1.x,p1.y,p2.x,p2.y,p3.x,p3.y);
  o:=l2p(serper(p1,p2),serper(p2,p3));
  alp1:=arctan2(vp(v(o,p1),v(o,p2)),sp(v(o,p1),v(o,p2)));
  if alp1<0 then alp1:=alp1+2*pi;
  alp2:=arctan2(vp(v(o,p1),v(o,p3)),sp(v(o,p1),v(o,p3)));
  if alp2<0 then alp2:=alp2+2*pi;
  alp1:=min(alp1,2*pi-alp1);
  alp2:=min(alp2,2*pi-alp2);
  for p:=3 to 10000 do begin
    alp0:=2*pi/p;
    if abs(alp1/alp0-round(alp1/alp0))<1e-5 then begin
      if abs(alp2/alp0-round(alp2/alp0))<1e-5 then begin
        writeln(p*dst(o,p1)*sin(alp0)/2:0:15);
        halt;
      end;
    end;
  end;
end.