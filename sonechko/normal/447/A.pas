var a:array[0..100000]of longint;
    n,m,i,j,k,l,r:Longint;
  begin
    read(l,n);
    for i:=1 to n do
     begin
       read(r);
       if a[r mod l]=0 then a[r mod l]:=1 else begin writeln(i); halt; end;
     end;
    writeln('-1');
  end.