var n,m,i,j,k,l,r:Longint;
    a:array['A'..'Z']of longint;
    q,h:char;
    b:array[0..100+5,0..100+5]of char;
  begin
    readln(n,m,q,h);

    for i:=1 to n do
     begin
       for j:=1 to m do
        read(b[i,j]);
       readln;
     end;
    k:=0;
    for i:=1 to n do
     for j:=1 to m do
      if (b[i,j]<>'.') then
       if (b[i,j]<>h) and (a[b[i,j]]<>1) and
          ((b[i+1,j]=h) or
           (b[i-1,j]=h) or
           (b[i,j-1]=h) or
           (b[i,j+1]=h)) then begin inc(k); a[b[i,j]]:=1; end;
    writeln(k);
  end.