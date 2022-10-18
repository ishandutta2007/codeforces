var n,m,i,j,k,ans,l,r,ll,rr:longint;
    a,b:array[0..1000000]of longint;
  begin
    read(n,m);
    for i:=1 to n do
     read(a[i]);
    l:=1;
    k:=0;
    for r:=1 to n do
     begin
       if b[a[r]]=0 then inc(k);
       inc(b[a[r]]);
       if (k<=m) and (ans<r-l+1) then begin ans:=r-l+1; ll:=l; rr:=r; end else
        begin
          while k>m do
           begin
             if b[a[l]]=1 then dec(k);
             dec(b[a[l]]);
             inc(l);
           end;
        end;
     end;
    writeln(ll,' ',rr);
  end.