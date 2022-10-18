var n,m,i,j,k,ans,l,r:longint;
    a,ll,rr:array[1..1000000]of longint;
  begin
    read(n);
    for i:=1 to n do
     begin
       read(l);
       inc(a[l]);
       if ll[l]=0 then ll[l]:=i;
       rr[l]:=i;
     end;
   ans:=maxlongint;
   for i:=1 to 1000000 do
    if a[i]>k then k:=a[i];
   for i:=1 to 1000000 do
    if (a[i]=k) and (rr[i]-ll[i]+1<ans) then begin ans:=rr[i]-ll[i]+1; l:=ll[i]; r:=rr[i]; end;
   writeln(l,' ',r);
  end.