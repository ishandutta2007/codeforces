var n,m,i,j,k,ans,l,r,k_1,k_2:longint;
    a,b:array[1..100]of longint;
  begin
    read(n,m,k);
    for i:=1 to k do
     begin
       read(l);
       a[l]:=1;
     end;
    k_1:=k;
    read(k);
    for i:=1 to k do
     begin
       read(l);
       b[l]:=1;
     end;
    k_2:=k;
    for i:=0 to 1000000 do
     begin
       l:=i mod n;
       r:=i mod m;
       if (a[l]=1) and (b[r]=1) then continue;
       if (a[l]=1) and (b[r]=0) then begin inc(k_2); b[r]:=1; end;
       if (a[l]=0) and (b[r]=1) then begin inc(k_1); a[l]:=1; end;
       if (k_1>=n) and (k_2>=m) then begin writeln('Yes'); halt; end;
     end;
    writeln('No');
  end.