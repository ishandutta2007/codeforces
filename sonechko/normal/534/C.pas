uses math;
var n,m,k,ans,l,r,ll,rr:int64;  i,j:longint;
    a:array[1..200000]of int64;
  begin
    read(n,m);
    for i:=1 to n do
     begin
      read(a[i]);
      l:=l+a[i];
     end;
    for i:=1 to n do
     begin
       ll:=m-(l-a[i]);if ll<1 then ll:=1;
       rr:=m-(n-1);if rr>a[i] then rr:=a[i];
       write(a[i]-(rr-ll+1),' ');
     end;
    writeln;
  end.