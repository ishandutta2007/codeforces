var a:array[0..4,0..4]of longint;
    i,j,k,l,r:longint;
  begin
    for i:=1 to 4 do
     for j:=1 to 4 do
      a[i,j]:=1;
    for i:=1 to 3 do
     for j:=1 to 3 do
      begin
        read(l);
        l:=l mod 2;
        if l=1 then
         begin
           a[i,j]:=1-a[i,j];
           a[i-1,j]:=1-a[i-1,j];
           a[i+1,j]:=1-a[i+1,j];
           a[i,j-1]:=1-a[i,j-1];
           a[i,j+1]:=1-a[i,j+1];
         end;
      end;
    for i:=1 to 3 do
     begin
      for j:=1 to 3 do
       write(a[i,j]);
      writeln;
     end;
  end.
010
011
100