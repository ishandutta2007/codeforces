uses math;
var ans,n,m,k:int64;
  begin
    read(n,m,k);
    ans:=min(n+m+k,n+n+m+m);
    ans:=min(min(ans,n+n+k+k),m+m+k+k);
    writeln(ans);
  end.