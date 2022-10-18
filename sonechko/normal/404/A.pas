var a:array[1..1000,1..1000]of char;
    i,j,n,k,l,m:longint;
    s:string;
    aa,bb:char;
 begin
   readln(n);
   for i:=1 to n do
    begin
      for j:=1 to n do
       read(a[i,j]);
      readln;
    end;
   aa:=a[1,1];
   bb:=a[1,2];
   s:='YES';
   for i:=1 to n do
    for j:=1 to n do
     if ((i=j) or (i+j-1=n)) and (a[i,j]<>aa) then s:='NO' else
     if (i<>j) and (i+j-1<>n) and (a[i,j]<>bb) then s:='NO';
   if aa<>bb then writeln(s) else writeln('NO');
 end.