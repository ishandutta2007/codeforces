var n,m,i,j,k,l,r:longint;
    s:int64;
 begin
   read(n);
   l:=-maxlongint;
   k:=0;
   s:=0;
   for i:=1 to n do
    begin
      read(r);
      if l=r then inc(k) else
       begin
         for j:=1 to k do
          s:=s+j;
         k:=1;
         l:=r;
       end;
    end;
   for j:=1 to k do
    s:=s+j;
   writeln(s);
 end.