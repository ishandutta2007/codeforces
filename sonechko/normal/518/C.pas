var n,m,k,ans,l,r:int64;  i,j:longint;
    a,b,c:array[1..100000]of int64;
  begin
    read(n,m,k);
    r:=1;
    l:=0;
    for i:=1 to n do
     begin
       read(a[i]);
       c[a[i]]:=i;
       inc(l);
       b[i]:=r;
       if l=k then begin l:=0; inc(r); end;
     end;
    for i:=1 to m do
     begin
       read(l);
       l:=c[l];
       ans:=ans+(b[l]);
       if l>1 then
        begin
         c[a[l]]:=c[a[l]]-1;
         c[a[l-1]]:=c[a[l-1]]+1;

         r:=a[l];
         a[l]:=a[l-1];
         a[l-1]:=r;

        end;
     end;

    writeln(ans);
  end.