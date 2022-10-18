var n,m,k,k1,l,l1,r,r1,r2,l2:int64;  i,j:longint;
 function sum(x:int64):int64;
  begin
    sum:=(x+1)*(x div 2)+(x mod 2)*((x+1) div 2);
  end;
  begin
    read(n,m);
    l:=0;
    {for i:=1 to n mod m do
     l:=l+sum(n div m+1-1);
    for i:=1 to m-n mod m do
     l:=l+sum(n div m-1); }
    l:=sum(n div m+1-1)*(n mod m);
    l:=l+sum(n div m-1)*(m-n mod m);
    r:=sum(n-m+1-1);
    writeln(l,' ',r);
  end.