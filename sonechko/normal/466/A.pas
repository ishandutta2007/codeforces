 var n,m,i,j,k,l,r:longint;
   begin
     read(n,m,l,r);
     if l*m<=r then writeln(n*l) else
     if n mod m=0 then writeln((n div m)*r) else
     if n mod m*l<r then writeln((n div m)*r+(n mod m)*l) else
                         writeln((n div m)*r+r);
   end.