var n,m,i,j,k,l,r:longint;
    a:array[1..12]of longint;
  begin
    read(n);
    for i:=1 to 12 do
     read(a[i]);
    for i:=1 to 11 do
     for j:=i+1 to 12 do
      if a[i]<a[j] then begin k:=a[i]; a[i]:=a[j]; a[j]:=k; end;
    l:=0;
    for i:=1 to 12 do
     if l>=n then begin writeln(i-1); halt; end else l:=l+a[i];
    IF L>=N THEN WRITElN(12) ELSE writeln('-1');
  end.