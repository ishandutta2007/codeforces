var k,n,x,i,j:longint;
  begin
    read(n,x);
    k:=0;
    for i:=1 to n do
     begin
       read(j);
       k:=k+j;
     end;
    if k<0 then k:=k*-1;
    if k mod x=0 then writeln(k div x)
                 else writeln(k div x+1);
  end.