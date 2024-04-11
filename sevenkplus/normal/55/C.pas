var x,y:array[1..100] of longint;
    n,m,p,i:longint;
    f:boolean;
begin
  readln(n,m,p);
  for i:=1 to p do readln(x[i],y[i]);
  f:=true;
  for i:=1 to p do
    if (x[i]<=5) or (y[i]<=5) or (x[i]>=n-4) or (y[i]>=m-4) then f:=false;
  if f then writeln('NO') else writeln('YES');
end.