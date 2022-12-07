var
 y,p,l,s,n,i,j,k:longint;
 x,ans:int64;
 f:array[1..1000000]of longint;
 q:array[0..9]of int64;
begin
 readln(n);
 for i:=1 to 9 do f[i]:=i;
 p:=n;
 if p<100 then p:=100;
 for i:=10 to p do
 begin
  s:=0;
  l:=i;
  while l>0 do
  begin
   inc(s,l mod 10);
   l:=l div 10;
  end;
  f[i]:=f[s];
 end;
 fillchar(q,sizeof(q),0);
 for i:=1 to n do inc(q[f[i]]);
 x:=0;
 ans:=0;
 for i:=1 to n do for j:=1 to n do if i*j>n then break else
 if f[i*j]<>f[f[i]*f[j]] then inc(ans)else inc(x);
 for i:=1 to n do
 begin
  y:=f[i];
  for j:=1 to 9 do for k:=1 to 9 do if y=f[j*k] then inc(ans,q[j]*q[k]);
 end;
 writeln(ans-x);
end.