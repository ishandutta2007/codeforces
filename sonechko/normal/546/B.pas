var n,m,i,j,k,ans,l,r:longint;
    a,b:array[1..6000]of longint;
  begin
    read(n);
    for i:=1 to n do
     begin
      read(a[i]);
      b[a[i]]:=b[a[i]]+1;
     end;
    l:=0;
    ans:=0;
    for i:=1 to 6000 do
     begin
      inc(b[i],l);
      ans:=ans+l;
      if b[i]>1 then l:=b[i]-1 else l:=0;
     end;
    writeln(ans);

  end.