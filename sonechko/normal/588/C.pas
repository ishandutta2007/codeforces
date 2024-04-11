var n,m,i,j,k,ans,l,r:longint;
    a:array[-1..10000000]of longint;
  begin
    read(n);
    for i:=1 to n do
     begin
       read(l);
       a[l]:=a[l]+1;
     end;
    for i:=0 to 10000000 do
     if (a[i-1]>1) then begin a[i]:=a[i]+(a[i-1] div 2); a[i-1]:=a[i-1] mod 2; end;
    for i:=0 to 10000000 do
     ans:=ans+a[i];
    writeln(ans);
  end.