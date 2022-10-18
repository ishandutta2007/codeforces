var n,m,i,j,k,l,r,ans,ans1:longint;
    a:array[1..1000]of longint;
  begin
    read(n);
    for i:=1 to n do
     read(a[i]);
    l:=1;
    r:=n;
    ans:=0;
    ans1:=0;
    k:=1;
    while l<=r do
     begin
       if k mod 2=1 then
        begin
          if a[l]>a[r] then begin ans:=ans+a[l]; l:=l+1; end else
                            begin ans:=ans+a[r]; r:=r-1; end;
        end else
        begin
          if a[l]>a[r] then begin ans1:=ans1+a[l]; l:=l+1; end else
                            begin ans1:=ans1+a[r]; r:=r-1; end;
        end;
       inc(k);
     end;
    writeln(ans,' ',ans1);
  end.