var
 g,a,b,c,x,y,wa,wb:int64;

function gcd(a,b:int64; var x,y:int64):int64;
var
 xx,yy:int64;
begin
 if b=0 then
 begin
  gcd:=a;
  x:=1;
  y:=0;
  exit;
 end;
 gcd:=gcd(b,a mod b,xx,yy);
 x:=yy;
 y:=xx-(a div b)*yy;
end;

begin
{ assign(input,'input.txt');
 reset(input);}
 readln(a,b,c);
 if (a=0)and(b=0)then
 begin
  if c=0 then writeln('0 0')else writeln(-1);
  halt;
 end;
 c:=-c;
 if c<0 then
 begin
  c:=-c;
  a:=-a;
  b:=-b;
 end;
 wa:=1;
 if a<0 then
 begin
  wa:=-1;
  a:=-a;
 end;
 wb:=1;
 if b<0 then
 begin
  wb:=-1;
  b:=-b;
 end;
 g:=gcd(a,b,x,y);
 if c mod g>0 then
 begin
  writeln(-1);
  halt;
 end;
 x:=wa*c div g*x;
 y:=wb*c div g*y;
 writeln(x,' ',y);
end.