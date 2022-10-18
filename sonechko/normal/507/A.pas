var n,m,i,j,k,l,r:longint;
    a,b:array[1..1000]of longint;
  begin
    read(n,m);
    a[n+1]:=maxlongint;
    for i:=1 to n do
     begin
     read(a[i]);  b[i]:=i; end;
    for i:=1 to n do
     for j:=1 to n do
      if a[i]<a[j] then begin k:=a[i]; a[i]:=a[j]; a[j]:=k;
                              k:=b[i]; b[i]:=b[j]; b[j]:=k; end;
    for i:=1 to n+1 do
     if a[i]<=m then m:=m-a[i] else break;
    writeln(i-1);
    for i:=1 to i-1 do
     write(b[i],' ');
  end.