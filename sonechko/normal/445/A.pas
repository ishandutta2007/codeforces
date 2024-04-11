var n,m,i,j,k,ans,l,r:Longint;
    a:array[1..100,1..100]of char;
    g:char;
  begin
    readln(n,m);
    for i:=1 to n do
     begin
       for j:=1 to m do
        read(a[i,j]);
       readln;
     end;
    for i:=1 to n do
     begin
       if i mod 2=0 then g:='B' else g:='W';
       for j:=1 to m do
        begin
          if g='B' then g:='W' else g:='B';
          if a[i,j]='.' then a[i,j]:=g;
        end;
     end;
    for i:=1 to n do
     begin
      for j:=1 to m do
       write(a[i,j]);
      writeln;
     end;
  end.