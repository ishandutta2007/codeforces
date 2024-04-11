var n,m,i,j,k,l,r:longint;
  begin
    read(n,m);
    k:=n div 2+n mod 2;
    for i:=k to n do
     if i mod m=0 then begin writeln(i); halt; end;
    writeln('-1');
  end.