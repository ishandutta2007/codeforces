uses math;
var n,m,i,j,k,ans,l,r:longint;

  begin
    read(n,m);
    write(min(n,m),' ');
    l:=max(n,m);
    l:=l-min(n,m);
    writeln(l div 2);
  end.