var a:array[1..300,1..300] of longint;
    n,m,i,j,k,x,y,z:longint;
    s:int64;
begin
  readln(n);
  for i:=1 to n do
    for j:=1 to n do read(a[i,j]);
  for k:=1 to n do
    for i:=1 to n do if i<>k then
      for j:=1 to n do if (i<>j) and (k<>j) then
        if a[i,k]+a[k,j]<a[i,j] then a[i,j]:=a[i,k]+a[k,j];
  readln(m);s:=0;
  for i:=1 to n do
    for j:=i+1 to n do inc(s,a[i,j]);
  for m:=1 to m do
    begin
      readln(x,y,z);
      if z<a[x,y] then
        begin
          s:=0;
          for i:=1 to n do
            for j:=i+1 to n do
              begin
                if a[i,x]+z+a[y,j]<a[i,j] then a[i,j]:=a[i,x]+z+a[y,j];
                if a[i,y]+z+a[x,j]<a[i,j] then a[i,j]:=a[i,y]+z+a[x,j];
                a[j,i]:=a[i,j];inc(s,a[i,j]);
              end;
        end;
      writeln(s);
    end;
end.