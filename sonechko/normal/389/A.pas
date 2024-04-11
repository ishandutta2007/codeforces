var n,m,i,j,k,ans,l,r:longint;
    a:array[1..100]of longint;
procedure get;
 var i,j,ans:longint;
  begin
    for i:=2 to n do
     if a[i]>a[i-1] then a[i]:=a[i]-a[i-1] else
     if a[i]<a[i-1] then a[i-1]:=a[i-1]-a[i];
    j:=0;
    ans:=a[1];
    for i:=2 to n do
     begin if a[i]<>a[i-1] then begin j:=1; end; ans:=ans+a[i];  end;
    //writeln(ans);
    if j=0 then begin writeln(ans);
    halt; end;
  end;
  begin
    read(n);
    for i:=1 to n do
     read(a[i]);
    for k:=1 to 10000000 do
     get;
  end.