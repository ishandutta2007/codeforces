var n,m,j,k,ans,l,r:int64;    i:longint;
    a:array[1..1000, 1..1000]of longint;
  begin
    read(n);
    for i:=1 to n do
     begin
       read(l,r);
       a[l,r]:=1;
     end;
    n:=1000;
    for i:=1 to 1000 do
     begin
       l:=1;
       r:=i;
       k:=0;
       while (l<=n) and (r<=n) do
        begin
          if a[l,r]=1 then k:=k+1;
          inc(l);
          inc(r);
        end;
       ans:=ans+(k*(k-1)) div 2;
     end;
    for i:=2 to 1000 do
     begin
       l:=i;
       r:=1;
       k:=0;
       while (l<=n) and (r<=n) do
        begin
          if a[l,r]=1 then k:=k+1;
          inc(l);
          inc(r);
        end;
       ans:=ans+(k*(k-1)) div 2;
     end;
    for i:=2 to 1000 do
     begin
       l:=1;
       r:=i;
       k:=0;
       while (l<=n) and (r>=1) do
        begin
          if a[l,r]=1 then k:=k+1;
          inc(l);
          dec(r);
        end;
       ans:=ans+(k*(k-1)) div 2;
     end;
     for i:=2 to 1000 do
     begin
       l:=i;
       r:=n;
       k:=0;
       while (l<=n) and (r>=1) do
        begin
          if a[l,r]=1 then k:=k+1;
          inc(l);
          dec(r);
        end;
       ans:=ans+(k*(k-1)) div 2;
     end;
    writeln(ans);
  end.