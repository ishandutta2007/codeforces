var n,m,i,j,l,r:longint;
    a:array[-10..10]of int64; k:int64;
   begin
     read(n);
     k:=0;
     for i:=1 to n do
      begin
        read(l);
        k:=k+a[l*-1];
        inc(a[l]);
      end;
     writeln(k);
   end.