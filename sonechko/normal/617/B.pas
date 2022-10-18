uses math;
var n,m,i,j,k,ans,l,r,x1,y1,x2,y2:longint;
    a,dp:array[0..1000]of int64;
  begin
    read(n);
    for i:=1 to n do
     read(a[i]);
    dp[0]:=1;
    for i:=1 to n do
     if a[i]=1 then
     begin
       dp[i]:=dp[i-1];
       for j:=i-1 downto 1 do
        if a[j]=0 then dp[i]:=dp[i]+dp[j-1] else break;
     end else
     begin
       l:=0;
       for j:=i-1 downto 1 do
        if a[j]=1 then begin l:=j; break; end;
       if l<>0 then
        begin
          dp[i]:=dp[i]+dp[l-1];
          for j:=l-1 downto 1 do
           if a[j]=0 then dp[i]:=dp[i]+dp[j-1] else break;
        end;
     end;
    writeln(dp[n]);
  end.