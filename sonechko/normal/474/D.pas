var a,b:array[0..100000]of int64;
    i,j,n,m,k,l,r:longint;

 begin
   read(n,k);
   for i:=0 to 100000 do
    a[i]:=1;
   for i:=k to 100000 do
   begin
     a[i]:=(a[i-1]+a[i-k]) mod 1000000007;
   end;
   for i:=1 to 100000 do
    b[i]:=(b[i-1]+a[i]) mod 1000000007;
     b[0]:=0;
     a[0]:=0;
   for i:=1 to n do
    begin
      read(l,r);
      if b[r]-b[l-1]<0 then writeln(b[r]-b[l-1]+1000000007)
                       else writeln(b[r]-b[l-1]);
    end;
 end.