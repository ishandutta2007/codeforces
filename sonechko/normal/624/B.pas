uses math;
var n,m,k,ans,l,r,ll,rr:int64;
    i,j:longint;
    a:array[1..26]of int64;
  begin
    read(n);
    for i:=1 to n do
     read(a[i]);
    for i:=1 to n do
     for j:=i+1 to n do
      if a[i]>a[j] then begin l:=a[i]; a[i]:=a[j]; a[j]:=l; end;
    l:=a[n];
    for i:=n downto 1 do
     begin
      if l<=0 then break;
      ans:=ans+min(l,a[i]);
      l:=min(a[i],l);
      l:=l-1;
     end;
   writeln(ans);
  end.