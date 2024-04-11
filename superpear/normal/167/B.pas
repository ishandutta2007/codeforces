var n,l,e,i,j,k,q:longint;
    ans,s:extended;
    a,p:array[0..1000] of longint;
    f:array[0..210,0..210,-210..210] of extended;
begin
  readln(n,l,e);
  for i:=1 to n do
    read(p[i]);
  for i:=1 to n do
    read(a[i]);
  for i:=0 to 210 do
    for j:=0 to 210 do
      for k:=-210 to 210 do
        f[i,j,k]:=0;
  f[0,0,e]:=1;
  for i:=0 to n-1 do
    for j:=0 to n do
      for k:=-200 to 200 do
        if f[i,j,k]>0 then
          begin
            //writeln(i,' ',j,' ',k,' ',f[i,j,k]:0:10);
            s:=p[i+1]/100;
            q:=k+a[i+1];
            if q>200 then q:=200;
            f[i+1,j+1,q]:=f[i+1,j+1,q]+f[i,j,k]*s;
            f[i+1,j,k]:=f[i+1,j,k]+f[i,j,k]*(1-s);
          end;
  ans:=0;
  for i:=l to n do
    for j:=0 to 200 do
      ans:=ans+f[n,i,j];
  writeln(ans:0:10);
end.