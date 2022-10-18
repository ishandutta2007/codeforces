var i,j,k,ans,l,r,n,m:longint;
    a:array[-1..1000+1,-1..1000+1]of longint;
  begin
    read(n,m,k);
    for i:=1 to k do
     begin
       read(l,r);
       a[l,r]:=1;
       if a[l-1,r]+a[l-1,r-1]+a[l,r-1]=3 then begin writeln(i); halt; end;
       if a[l-1,r]+a[l-1,r+1]+a[l,r+1]=3 then begin writeln(i); halt; end;
       if a[l,r+1]+a[l+1,r+1]+a[l+1,r]=3 then begin writeln(i); halt; end;
       if a[l+1,r]+a[l+1,r-1]+a[l,r-1]=3 then begin writeln(i); halt; end;
     end;
    writeln(0);
  end.