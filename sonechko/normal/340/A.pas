var n,m,i,j,ans,l,r:longint;  k:int64;
function nsd(l,r:longint):longint;
 begin
   while (l>0) and (r>0) do
    if l>r then l:=l mod r else r:=r mod l;
   exit(l+r);
 end;
function nsk(l,r:longint):longint;
 begin
   exit((l*r) div nsd(l,r));
 end;
 begin
   read(l,r,n,m);
   k:=nsk(l,r);
   if k>n then n:=k;
   writeln((m div k)-((n-1) div k));
 end.