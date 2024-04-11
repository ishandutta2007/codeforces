var
 ans,n,m,i,j,k:longint;
 a,b,c:int64;
 x1,y1,x2,y2:array[1..1000]of int64;
 ms:array[1..1000,1..1000]of longint;
begin
 readln(n,m);
 for i:=1 to n do read(x1[i],y1[i]);
 for i:=1 to m do read(x2[i],y2[i]);
 fillchar(ms,sizeof(ms),0);
 for i:=1 to n do for j:=1 to n do if x1[i]<x1[j] then
 begin
  a:=y1[j]-y1[i];
  b:=x1[i]-x1[j];
  c:=-x1[i]*a-y1[i]*b;
  for k:=1 to m do if (x2[k]>x1[i])and(x2[k]<=x1[j])and(a*x2[k]+b*y2[k]+c>0)then inc(ms[i,j]);
  ms[j,i]:=-ms[i,j];
 end;
 ans:=0;
 for i:=1 to n do for j:=i+1 to n do for k:=j+1 to n do
 begin
  if ms[i,j]+ms[j,k]+ms[k,i]=0 then inc(ans);
 end;
 writeln(ans);
end.