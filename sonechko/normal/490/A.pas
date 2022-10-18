uses math;
var n,m,i,j,k,l,r:longint;
    a:array[1..3,0..5000]of longint;
  begin
    read(n);
    for i:=1 to n do
     begin
       read(l);
       inc(a[l,0]); a[l,a[l,0]]:=i;
     end;
    l:=min(a[1,0],min(a[2,0],a[3,0]));
    writeln(l);
    for i:=1 to l do
     writeln(a[1,i],' ',a[2,i],' ',a[3,i]);

  end.