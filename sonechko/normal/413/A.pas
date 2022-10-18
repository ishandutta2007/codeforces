var n,m,min,max,k,l,r,i,j:longint;
    a:array[1..100000]of longint;
  begin
    read(n,m,min,max);
    for i:=1 to m do
     read(a[i]);
    l:=-maxlongint;
    r:=maxlongint;
    for i:=1 to m do
     begin
     if a[i]>l then l:=a[i];
     if a[i]<r then r:=a[i];
     end;
    if (l=max) and (r=min) then writeln('Correct') else
    if (l<=max) and (r=min) and (n-m>=1)then writeln('Correct') else
    if (l=max) and (r>=min) and (n-m>=1)then writeln('Correct') else
    if (l<=max) and (r>=min) and (n-m>=2) then writeln('Correct') else
    writeln('Incorrect');
  end.