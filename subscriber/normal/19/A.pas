var
 n,m1,m2,m3,i,j,mi,x,y,a,b:longint;
 e:integer;
 aa,t:string;
 p1,p2,p3,f:array[1..100]of longint;
 q,s:array[1..100]of string;

function id(ss:string):longint;
var
 i:longint;
begin
 for i:=1 to n do if s[i]=ss then
 begin
  id:=i;
  exit;
 end;
end;

begin
 readln(n);
 for i:=1 to n do readln(s[i]);
 for i:=1 to n*(n-1)div 2 do
 begin
  readln(t);
  x:=id(copy(t,1,pos('-',t)-1));
  delete(t,1,pos('-',t));
  y:=id(copy(t,1,pos(' ',t)-1));
  delete(t,1,pos(' ',t));
  val(copy(t,1,pos(':',t)-1),a,e);
  delete(t,1,pos(':',t));
  val(t,b,e);
  if a=b then
  begin
   inc(p1[x]);
   inc(p1[y]);
  end else if a>b then inc(p1[x],3)else inc(p1[y],3);
  inc(p2[x],a);
  inc(p2[y],b);
  inc(p3[x],b);
  inc(p3[y],a);
 end;
 fillchar(f,sizeof(f),0);
 for i:=1 to n shr 1 do
 begin
  m1:=-1;
  m2:=-1;
  m3:=-1;
  for j:=1 to n do if f[j]=0 then
  if (p1[j]>m1)or(p1[j]=m1)and(p2[j]-p3[j]>m2)or
  (p1[j]=m1)and(p2[j]-p3[j]=m2)and(p2[j]>m3)then
  begin
   m1:=p1[j];
   m2:=p2[j]-p3[j];
   m3:=p2[j];
   mi:=j;
  end;
  f[mi]:=1;
  q[i]:=s[mi];
 end;
 fillchar(f,sizeof(f),0);
 for i:=1 to n shr 1 do
 begin
  aa:=#200;
  for j:=1 to n shr 1 do if (f[j]=0)and(q[j]<aa)then
  begin
   aa:=q[j];
   mi:=j;
  end;
  f[mi]:=1;
  writeln(aa);
 end;
end.