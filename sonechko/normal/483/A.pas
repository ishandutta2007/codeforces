var n,m,l,r:int64;
    i,j,k:int64;
function pro(n,m:int64):boolean;
 begin
   while (n>0) and (m>0) do
    if n>m then n:=n mod m else m:=m mod n;
   if (n+m)=1 then exit(true) else exit(false);
 end;
  begin
    read(l,r);
    i:=l;
    while (i<=r) do
     begin
      j:=i+1;
      while (j<=r) do
       begin
        k:=j+1;
        while (k<=r) do
         begin
          if (pro(i,j)) and (pro(j,k)) and not(pro(i,k)) then begin writeln(i,' ',j,' ',k); halt; end;
          inc(k);
         end;
        inc(j);
       end;
      inc(i);
     end;
  writeln('-1');
  end.