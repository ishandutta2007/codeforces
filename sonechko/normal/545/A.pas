var n,m,i,j,k,ans,l,r:longint;
    a:array[1..100,1..100]of longint;
    b:array[1..100]of longint;
  begin
    read(n);
    for i:=1 to n do
     for j:=1 to n do
      read(a[i,j]);
    for k:=1 to n do
     begin
       ans:=0;
       for j:=1 to n do
        if (a[k,j]=1) or (a[k,j]=3) then begin ans:=1; break; end;
       for i:=1 to n do
        if (a[i,k]=2) or (a[i,k]=3) then begin ans:=1; break; end;
       if ans=0 then begin inc(m); b[m]:=k; end;
     end;
    writeln(m);
    for i:=1 to m do
     write(b[i],' ');
    writeln;
  end.