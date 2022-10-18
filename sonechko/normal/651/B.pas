var n,m,i,j,k,ans,l,r:longint;
    a:array[1..1000]of longint;
  begin
    read(n);
    for i:=1 to n do
     begin
       read(l);
       a[l]:=a[l]+1;
     end;
    k:=0;
    l:=0;
    while (k<n) do
     begin
       r:=0;
       for i:=l+1 to 1000 do
        if a[i]>0 then begin
        k:=k+1;
        a[i]:=a[i]-1;
        r:=1;
        if (l<>0) then ans:=ans+1;
        l:=i;
        break; end;
       if (r=0) then l:=0;
     end;
    writeln(ans);
  end.