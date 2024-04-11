var n,m,i,j,k,l,r:longint;
    a,b:array[1..100,1..100]of longint;
  begin
    read(n,m);
    for i:=1 to n do
     for j:=1 to m do
      read(a[i,j]);
    for i:=1 to n do
     for j:=1 to m do
       b[i,j]:=1;
    for i:=1 to n do
     for j:=1 to m do
      if a[i,j]=0 then
       begin
         for l:=1 to n do
          b[l,j]:=0;
         for r:=1 to m do
          b[i,r]:=0;
       end;
    for i:=1 to n do
     for j:=1 to m do
      begin
         k:=0;
         for l:=1 to n do
          if b[l,j]=1 then k:=1;
         for r:=1 to m do
          if b[i,r]=1 then k:=1;
         if k<>a[i,j] then begin writeln('NO'); halt; end;
      end;
    writeln('YES');
    for i:=1 to n do
     begin
     for j:=1 to m do
      write(b[i,j],' ');
      writeln;
     end;
  end.