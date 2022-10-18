var n,m,j,k,ans,l,r,x,y,z,w:int64;
    i:longint;
    a,b:array[1..10]of longint;
 begin
   read(n,m);
   for i:=1 to n do
    read(a[i]);
   l:=1;
   for i:=n downto 1 do
    begin
      x:=x+a[i]*l;
      l:=l*m;
    end;
   read(n,m);
   for i:=1 to n do
    read(a[i]);
   l:=1;
   for i:=n downto 1 do
    begin
      y:=y+a[i]*l;
      l:=l*m;
    end;
   if x<y then writeln('<') else
   if x>y then writeln('>') else writeln('=');
 end.