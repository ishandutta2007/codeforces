uses math;
var n,m,k:longint;
  begin
    read(n,m,k);
    writeln(max(n+m+k,max(n*m*k,max((n+m)*k,n*(m+k)))));
  end.