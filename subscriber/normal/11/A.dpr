var
 x,ans,i,d,n:longint;
 a:array[1..10000]of longint;
begin
 readln(n,d);
 for i:=1 to n do read(a[i]);
 ans:=0;
 for i:=2 to n do if a[i]<=a[i-1] then
 begin
  x:=(a[i-1]-a[i])div d+1;
  inc(ans,x);
  inc(a[i],x*d);
 end;
 writeln(ans);
end.