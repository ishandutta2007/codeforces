var a,b:array[1..1000000]of longint;
    n,k,m,i,l,r,j,ans,res,kk,ll:longint;
function cannot(l:longint):boolean;
  begin
   fillchar(b,sizeof(b),0);
   for i:=1 to l do
    b[a[i]]:=1;
   kk:=0;
   for i:=2 to n do
    inc(b[i],b[i-1]);
   i:=1;
   while (i<=n) do
    if (m+i-1<=n) and (b[i+m-1]-b[i-1]=0) then
     begin
      inc(kk);
      inc(i,m+1);
     end else inc(i);
    if kk>=k then exit(false) else exit(true);
  end;
  begin
    read(n,k,m,ll);
    for i:=1 to ll do
     read(a[i]);
    l:=0;
    r:=ll;
    while (l+1<r) do
     begin
       j:=(l+r) div 2;
       if cannot(j) then r:=j else l:=j;
     end;
    if cannot(l) then writeln(l) else
    if cannot(r) then writeln(r) else writeln(-1);
  end.