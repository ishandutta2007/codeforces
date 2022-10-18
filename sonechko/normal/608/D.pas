uses math;
var n,m,i,j,k,ans,l,r:longint;
    a:array[1..500]of longint;
    dp:array[0..500,0..500]of longint;
function get(l,r:longint):longint;
 var i,ans:longint;
   begin
     if l>r then exit(1000);
     if l+1=r then begin
     if a[l]=a[r] then exit(1) else exit(2);
     end;
     if l=r then exit(1);
     if dp[l,r]<>0 then exit(dp[l,r]);
     ans:=1000;
     if a[l]=a[r] then ans:=min(ans,get(l+1,r-1));
     for i:=l to r-1 do
      ans:=min(ans,get(l,i)+get(i+1,r));
     dp[l,r]:=ans;
     exit(ans);
   end;
   begin
     read(n);
     for i:=1 to n do
      read(a[i]);
     writeln(get(1,n));
   end.