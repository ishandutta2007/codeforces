{$APPTYPE CONSOLE}
{$D-,I-,L-,Q-,R-,S-,O+,H+}
uses
  SysUtils,Math;
type double=extended;
     int=longint;
     point=record
       x,y:double;
     end;
     line=record
       a,b,c:double;
     end;
var t1,t2,l,r,m,ans:double;
    p1,p2,p3:point;
    p:array[0..100]of point;
    kp:int;
const eps=1e-9;
function dst(a,b:point):double;
begin
  result:=sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));
end;
procedure add(a:point);
begin
  inc(kp);
  p[kp]:=a;
end;
procedure intC_C(a:point;r1:double;b:point;r2:double);
var l:line;
    ff:double;
    p1,p2:point;
begin
  if dst(a,b)>r1+r2+eps then exit;
  if dst(a,b)+min(r1,r2)+eps<max(r1,r2) then exit;
  l.a:=-2*(a.x-b.x);
  l.b:=-2*(a.y-b.y);
  l.c:=sqr(a.x)+sqr(a.y)-sqr(r1)-(sqr(b.x)+sqr(b.y)-sqr(r2));
  ff:=sqrt(sqr(l.a)+sqr(l.b));
  if abs(ff)<eps then exit;
  l.a:=l.a/ff;
  l.b:=l.b/ff;
  l.c:=l.c/ff;
  ff:=abs(a.x*l.a+a.y*l.b+l.c);
  p1.x:=a.x+l.a*ff;
  p1.y:=a.y+l.b*ff;
  if abs(p1.x*l.a+p1.y*l.b+l.c)>eps then begin
    p1.x:=a.x-l.a*ff;
    p1.y:=a.y-l.b*ff;
  end;
  ff:=sqrt(abs(sqr(r1)-sqr(ff)));
  p2.x:=p1.x-l.b*ff;
  p2.y:=p1.y+l.a*ff;
  add(p2);
  p2.x:=p1.x+l.b*ff;
  p2.y:=p1.y-l.a*ff;
  add(p2);
end;
function can(vm:double):boolean;
var r1,r2,r3:double;
    i:int;
    bol:boolean;
begin
  result:=false;
  r2:=t1-vm;
  r3:=t2-vm-dst(p2,p3);
  r1:=vm;
  if (r2<0)or(r3<0) then
    exit;
  kp:=0;
  add(p1);
  add(p2);
  add(p3);
  intC_C(p1,r1,p2,r2);
  intC_C(p1,r1,p3,r3);
  intC_C(p3,r3,p2,r2);
  for i:=1 to kp do begin
    bol:=true;
    if dst(p1,p[i])>r1+eps then bol:=false;
    if dst(p2,p[i])>r2+eps then bol:=false;
    if dst(p3,p[i])>r3+eps then bol:=false;
    if bol then begin
      result:=true;
      exit;
    end;
  end;
end;
begin
  //reset(input,'input.txt');
  //rewrite(output,'output.txt');
  readln(t2,t1);
  readln(p1.x,p1.y);
  readln(p2.x,p2.y);
  readln(p3.x,p3.y);
  t1:=t1+dst(p1,p2);
  t2:=t2+dst(p1,p3)+dst(p2,p3);
  l:=0;
  r:=100000;
  while r-l>1e-4 do begin
    m:=(l+r)/2;
    if can(m) then l:=m else r:=m;
  end;
  ans:=l;
  if t1>=dst(p1,p3)+dst(p3,p2)-eps then begin
    ans:=max(ans,min(t1,t2));
  end;
  writeln(ans:0:15);
end.