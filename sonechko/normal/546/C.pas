var n,m,i,j,k,ans,l,r,l1,r1:longint;
    a,b:array[1..10000000]of longint;
   begin
     read(n);
     read(n);
     for i:=1 to n do
      read(a[i]);
     read(m);
     for i:=1 to m do
      read(b[i]);
     j:=0;
     l1:=1;
     r1:=1;
     while j<1000000 do
      begin
        if (l1>n) then begin writeln(j,' 2'); halt; end;
        if (r1>m) then begin writeln(j,' 1'); halt; end;
        inc(j);
        if a[l1]>b[r1] then
         begin
           inc(n);
           a[n]:=b[r1];
           inc(n);
           a[n]:=a[l1];
           inc(l1);
           inc(r1);
         end else
         begin
           inc(m);
           b[m]:=a[l1];
           inc(m);
           b[m]:=b[r1];
           inc(l1);
           inc(r1);
         end;
      end;
     writeln('-1');
   end.