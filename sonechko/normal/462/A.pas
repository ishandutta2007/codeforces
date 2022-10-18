var n,m,i,j,k,l,r:longint;
    a:array[0..102,0..102]of char;
  begin
    readln(n);
    for i:=1 to n do
     begin
       for j:=1 to n do
        read(a[i,j]);
       readln;
     end;
    k:=0;
    for i:=1 to n do
     for j:=1 to n do
      begin
       k:=0;
       if (a[i+1,j]='o') then inc(k);
       if (a[i-1,j]='o') then inc(k);
       if (a[i,j-1]='o') then inc(k);
       if (a[i,j+1]='o') then inc(K);
       if k mod 2<>0 then begin writeln('NO'); halt; end;
      end;
    writeln('YES');
  end.