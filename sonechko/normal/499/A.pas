var n,m,i,j,k,ans:longint;
    l,r:array[0..100000]of longint;
  begin
    read(n,m);
    for i:=1 to n do
     begin
       read(l[i],r[i]);
     end;
    r[0]:=0;
    ans:=0;
    for i:=1 to n do
     begin
       j:=r[i-1]+1;
       while j+m<=l[i] do
        j:=j+m;
      ans:=ans+r[i]-j+1;
     end;
    writeln(ans);
  end.