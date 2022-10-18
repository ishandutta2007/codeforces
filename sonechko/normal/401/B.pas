var n,m,i,j,k1,k2,k,x,y,z:longint;
    a:array[0..10000]of longint;
  begin
    read(k,n);
    k:=k;
    for i:=1 to n do
     begin
       read(x);
       if x=1 then
       begin
        read(y,z);
        a[y]:=1;
        a[z]:=1;
       end;
       if x=2 then
        begin
          read(y);
          a[y]:=1;
        end;
     end;
    k1:=0;
    k2:=0;
    a[k]:=1;
    for i:=1 to k-1 do
     begin
       if (a[i]=0) then inc(k2);
     end;
    k1:=k2;
    a[0]:=1;
    i:=1;
    while i<=k-1 do
     begin
       if (a[i]=0) and (a[i+1]=0) then begin dec(k1); i:=i+2; end else inc(i);
     end;
    writeln(k1,' ',k2);
  end.