var
 a,t,i,_:longint;
 x1,y1,x2,y2:array[1..5]of extended;
 d:array[1..5]of extended;

function check(a,b,c:extended):byte;
begin
 check:=ord((b*b+c*c-a*a>-1e-7)and(a+b>c)and(a+c>b)and(c+b>a));
end;

function lej(x,y:extended; i:longint):byte;
var
 a,b,c,d1,d2:extended;
begin
 lej:=0;
 a:=y2[i]-y1[i];
 b:=x1[i]-x2[i];
 c:=-x1[i]*a-y1[i]*b;
 if abs(a*x+b*y+c)>1e-5 then exit;
 d1:=sqrt(sqr(x-x1[i])+sqr(y-y1[i]));
 d2:=sqrt(sqr(x-x2[i])+sqr(y-y2[i]));
 if abs(d[i]-(d1+d2))>1e-5 then exit;
 if abs(d1)<1e-7 then exit;
 if abs(d2)<1e-7 then exit;
 lej:=ord((4-d1/d2>-1e-9)and(4-d2/d1>-1e-9));
end;

procedure pro(l1,l2,l3:longint);
var
 b:longint;
begin
 b:=0;
 if (x2[l1]=x2[l2])and(y2[l1]=y2[l2])then
 begin
  if check(sqrt(sqr(x1[l1]-x1[l2])+sqr(y1[l1]-y1[l2])),d[l1],d[l2])=0 then exit;
  b:=1;
 end;
 if (x2[l1]=x1[l2])and(y2[l1]=y1[l2])then
 begin
  if check(sqrt(sqr(x1[l1]-x2[l2])+sqr(y1[l1]-y2[l2])),d[l1],d[l2])=0 then exit;
  b:=1;
 end;
 if (x1[l1]=x2[l2])and(y1[l1]=y2[l2])then
 begin
  if check(sqrt(sqr(x2[l1]-x1[l2])+sqr(y2[l1]-y1[l2])),d[l1],d[l2])=0 then exit;
  b:=1;
 end;
 if (x1[l1]=x1[l2])and(y1[l1]=y1[l2])then
 begin
  if check(sqrt(sqr(x2[l1]-x2[l2])+sqr(y2[l1]-y2[l2])),d[l1],d[l2])=0 then exit;
  b:=1;
 end;
 if b=0 then exit;
 if (lej(x1[l3],y1[l3],l1)=0)and(lej(x1[l3],y1[l3],l2)=0)then exit;
 if (lej(x2[l3],y2[l3],l1)=0)and(lej(x2[l3],y2[l3],l2)=0)then exit;
 if (lej(x1[l3],y1[l3],l1)=1)and(lej(x2[l3],y2[l3],l1)=1)then exit;
 if (lej(x1[l3],y1[l3],l2)=1)and(lej(x2[l3],y2[l3],l2)=1)then exit;
 a:=1;
end;

begin
{ assign(input,'1.in');
 reset(input);}
 readln(t);
 for _:=1 to t do
 begin
  a:=0;
  for i:=1 to 3 do read(x1[i],y1[i],x2[i],y2[i]);
  for i:=1 to 3 do d[i]:=sqrt(sqr(x1[i]-x2[i])+sqr(y1[i]-y2[i]));
  pro(1,2,3);
  pro(1,3,2);
  pro(2,3,1);
  if a=1 then writeln('YES')else writeln('NO');
 end;
end.