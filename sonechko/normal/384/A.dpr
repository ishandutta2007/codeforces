var n,m,i,j,k,l,r,ans:longint;
    a:array[1..1000,1..1000]of char;
  begin
    read(n);
    for i:=1 to n do
     if i mod 2=1 then a[1,i]:='C' else a[1,i]:='.';
    for i:=2 to n do
     for j:=1 to n do
      if a[i-1,j]='.' then a[i,j]:='C' else a[i,j]:='.';
    for i:=1 to n do
     for j:=1 to n do
      if a[i,j]='C' then inc(ans);
    writeln(ans);
    for i:=1 to n do
     begin
       for j:=1 to n do
        write(a[i,j]);
       writeln;
     end;
  end.                                   {}{}