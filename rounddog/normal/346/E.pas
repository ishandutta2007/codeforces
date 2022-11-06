
program cf201_7;

var
    i,m:longint;
    j,k,l,n,a,p,h:int64;

function max(x,y:int64):int64;
begin
  if x>y then max:=x else max:=y;
end;

function f(x,y,z:int64):int64;
begin
  if x>z div 2 then x:=z-x;
  if x*y>z then f:=f(z mod x,(x*y+z mod x) div z,x)
  else f:=max(x,z-x*(y-1));
end;

begin
  readln(m);
  for i:= 1 to m do
    begin
      readln(a,n,p,h);
      a:=a mod p;
      if a*n<p then j:=a
      else
        j:=f(a,n+1,p);
      if j>h then writeln('NO') else writeln('YES');
    end;
end.