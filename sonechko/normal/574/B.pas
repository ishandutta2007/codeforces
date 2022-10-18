var n,m,i,j,k,ans,l,r:longint;
    c,a,b:array[1..4000]of longint;
    d:array[1..4000,1..4000]of longint;
  begin
    read(n,m);
    for i:=1 to m do
     begin
       read(a[i],b[i]);
       inc(c[a[i]]);
       inc(c[b[i]]);
       d[a[i],b[i]]:=1;
       d[b[i],a[i]]:=1;
     end;
    ans:=maxlongint;
    for i:=1 to m do
     begin
       l:=a[i];
       r:=b[i];
       for j:=1 to n do
        if (d[j,l]=1) and (d[j,r]=1) then
         begin
           k:=j;
           //if (j=11) then begin writeln(j); writeln(c[l]+c[r]+c[k]); writeln('--------------'); end;
           if ans>c[l]+c[r]+c[k]-6 then ans:=c[l]+c[r]+c[k]-6;
         end;
     end;
    if ans=maxlongint then writeln('-1') else writeln(ans);
  end.