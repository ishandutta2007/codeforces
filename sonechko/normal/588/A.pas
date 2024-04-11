var n,m,i,j,k,ans,l,r:longint;
    a,b,c,d,e:array[0..100000]of longint;
  begin
    read(n);
    for i:=1 to n do
     begin
       read(b[i],a[i]);
       c[i]:=c[i-1]+b[i];
       if (a[i]<d[i-1]) then begin d[i]:=a[i]; e[i]:=i; end
       else begin d[i]:=d[i-1]; e[i]:=e[i-1]; end;
       if i=1 then begin d[i]:=a[i]; e[i]:=i; end;
     end;
    i:=n;
    while i>0 do
     begin
       ans:=ans+(c[i]-c[e[i]-1])*(d[i]);
       i:=e[i]-1;
     end;
    writeln(ans);
  end.