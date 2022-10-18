var n,m,i,j,k,r:longint;
    l,ans:int64;
    a:array[0..100000]of int64;
  begin
    read(n);
    l:=0;
    ans:=0;
    for i:=1 to n do
     read(a[i]);
    for i:=0 to n-1 do
     begin
      if a[i]<a[i+1] then l:=l-(a[i+1]-a[i]) else l:=l+a[i]-a[i+1];
      if l<0 then begin ans:=ans+abs(l); l:=0; end;
     end;
    writeln(ans);
  end.