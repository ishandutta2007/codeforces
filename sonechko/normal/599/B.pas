var n,m,i,j,k,ans,l,r:longint;
    a,b,c:array[1..100000]of longint;
  begin
    read(n,m);
    for i:=1 to n do
     read(a[i]);
    for i:=1 to n do
     if c[a[i]]=0 then c[a[i]]:=i else c[a[i]]:=-1;
    for i:=1 to m do
     read(b[i]);
    l:=0;
    for i:=1 to m do
     if c[b[i]]=-1 then begin l:=1; end else
     if c[b[i]]=0 then begin writeln('Impossible'); halt; end else
     a[i]:=c[b[i]];
    if l=1 then begin writeln('Ambiguity'); halt; end;
    writeln('Possible');
    for i:=1 to m do
     write(a[i],' ');
    writeln;
  end.