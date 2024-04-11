uses math;
var n,m,i,j,k,ans,l,r:longint;
    a:array[0..100000] of longint;
procedure rec(x,ans:longint);
  begin
   a[x]:=ans;
   if (x+x<=20000) and (a[x+x]>ans+1) then rec(x+x,ans+1);
   if (x-1>0) and (a[x-1]>ans+1) then rec(x-1,ans+1);
  end;
  begin
    read(n,m);
    a[n]:=0;
    for i:=1 to 20000 do
     a[i]:=maxlongint;
    a[n]:=0;
    rec(n,a[n]);
    writeln(a[m]);
  end.