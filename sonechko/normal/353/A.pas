var n,m,i,j,k,ans,l,r:longint;
    a,b:array[1..100]of longint;
  begin
    read(n);
    for i:=1 to n do
     begin
      read(a[i],b[i]);
      l:=l+a[i];
      r:=r+b[i];
      if a[i] mod 2<>b[i] mod 2 then ans:=1;
     end;
    if (l mod 2=0) and (r mod 2=0) then writeln('0') else
    if (l mod 2=1) and (r mod 2=1) and (ans=1) then writeln('1') else writeln('-1');
  end.