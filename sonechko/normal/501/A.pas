uses math;
var n,m,i,j,k,l,r:int64;

  begin
    read(n,m,l,r);
    k:= max(3*n div 10,n-(n div 250)*l);
    i:= max(3*m div 10,m-(m div 250)*r);
    if i=k then writeln('Tie') else
    if i>K then writeln('Vasya') else writeln('Misha');
  end.