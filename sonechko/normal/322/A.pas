var n,m,i,j,k,ans,l,r:longint;
    a,b,x,y:array[1..10000]of longint;
  begin
    read(n,m);
    l:=0;
    for i:=1 to n do
     for j:=1 to m do
      if (a[i]=0) or (b[j]=0) then begin a[i]:=1; b[j]:=1; inc(ans); x[ans]:=i; y[ans]:=j; end;
    writeln(ans);
    for i:=1 to ans do
     writeln(x[i],' ',y[i]);
  end.