uses math;
var a:array[1..5000,1..5000]of longint;
    b,dp:array[1..5000]of longint;
    n,m,i,j,k,ans,l,r,pp:longint;
procedure dfs(v:longint);
 var i,l,r:longint;
  begin
    if v>pp then begin dp[v]:=0; exit; end;
    dfs(v*2);
    dfs(v*2+1);
    l:=dp[v*2]+a[v,v*2];
    r:=dp[v*2+1]+a[v,v*2+1];
    //writeln(l,' ',r);
    ans:=ans+abs(l-r);
    dp[v]:=max(l,r);
  end;
  begin
    read(n);
    pp:=1;
    k:=n+1;
    while k>0 do
     begin
       dec(k);
       pp:=pp*2;
     end;
    pp:=pp-1;
    k:=1;
    for i:=1 to pp-1 do
     begin
      read(b[i]);
      a[(i+1) div 2,i+1]:=b[i];
     end;
    dfs(1);
    writeln(ans);
  end.