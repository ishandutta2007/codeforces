var
 kk,n,k,i,j,ans,t:longint;
 o,f:array[1..2000]of longint;
begin
 readln(n,k);
 fillchar(f,sizeof(f),0);
 f[1]:=1;
 kk:=0;
 for i:=2 to n do if f[i]=0 then
 begin
  inc(kk);
  o[kk]:=i;
  j:=i*i;
  while j<=n do
  begin
   f[j]:=1;
   inc(j,i);
  end;
 end;
 ans:=0;
 for i:=2 to n do if f[i]=0 then
 begin
  t:=0;
  for j:=2 to kk-1 do if o[j-1]+o[j]+1=i then t:=1;
  inc(ans,t);
 end;
 if ans>=k then writeln('YES')else writeln('NO');
end.