var x,n,m,i,j,l:longint;
    a:array[1..100]of longint;
  begin
   read(n,m);
   for i:=1 to m do
    read(a[i]);
   for i:=1 to m-1 do
    for j:=i+1 to m do
     if a[i]>a[j] then begin x:=a[i]; a[i]:=a[j]; a[j]:=x; end;
   l:=maxlongint;
   for i:=1 to m do
    for j:=i+n-1 to m do
     if a[j]-a[i]<l then l:=a[j]-a[i];
   writeln(l);

  end.