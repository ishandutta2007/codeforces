var n,m,i,j,k,l,r:longint;
    a:array[1..1000]of longint;
  begin
    read(n);
    a[n+1]:=0;
    k:=0;
    for i:=1 to n+1 do
     begin
       if i<>n+1 then read(l) else l:=0;
       if l=1 then inc(k) else
       if k<>0 then begin inc(m); a[m]:=k+1; k:=0; end;
     end;
    l:=0;
    for i:=1 to m do
     inc(l,a[i]);
    if l<>0 then l:=l-1;
    writeln(l);
  end.