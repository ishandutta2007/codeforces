var n,m,i,j,k,ans,l,r:longint;
    a,b:array[1..1000]of longint;
  begin
    read(n,m);
    for i:=1 to n do
     begin
       read(a[i],b[i]);
     end;
    for i:=1 to n do
     for j:=i+1 to n do
      if a[i]<a[j] then begin l:=a[i]; a[i]:=a[j]; a[j]:=l;
      l:=b[i]; b[i]:=b[j]; b[j]:=l; end;
      l:=0;
    for i:=1 to n do
     begin
       ans:=ans+m-a[i];
       l:=l+m-a[i];
       m:=a[i];
       if l<b[i] then begin ans:=ans+b[i]-l; l:=b[i]; end;
       //writeln(ans);
     end;
    ans:=ans+m;
    writeln(ans);
  end.