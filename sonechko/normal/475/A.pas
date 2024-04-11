var n,m,i,j,k,l,r:longint;
    a:array[1..4,1..11]of longint;
  begin
    read(n);
    for i:=1 to 11 do
     begin
       for j:=1 to 4 do
        if (n>0) then
         begin
          if (i=1) and (j=3) then begin dec(n); a[j,i]:=1; end else
          if (j<>3) then
          begin dec(n); a[j,i]:=1; end;
         end;
     end;
    writeln('+------------------------+');
    write('|');
    for i:=1 to 11 do
     if a[1,i]=1 then write('O.') else write('#.');
    writeln('|D|)');
    write('|');
    for i:=1 to 11 do
     if a[2,i]=1 then write('O.') else write('#.');
    writeln('|.|');
    if a[3,1]=1 then writeln('|O.......................|')
                else writeln('|#.......................|');
    write('|');
    for i:=1 to 11 do
     if a[4,i]=1 then write('O.') else write('#.');
    writeln('|.|)');
     writeln('+------------------------+');
  end.