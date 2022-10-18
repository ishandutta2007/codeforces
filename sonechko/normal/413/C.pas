uses math;
var n,m,i,j,l,r:longint;
    k:int64;
    a,b,c:array[1..1000000]of int64;
procedure sort(l,r: longint);
      var
         i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=a[(l+r) div 2];
         repeat
           while a[i]>x do
            inc(i);
           while x>a[j] do
            dec(j);
           if not(i>j) then
             begin
                y:=a[i];
                a[i]:=a[j];
                a[j]:=y;
                y:=b[i];
                b[i]:=b[j];
                b[j]:=y;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           sort(l,j);
         if i<r then
           sort(i,r);
      end;
  begin
    read(n,m);
    for i:=1 to n do
     read(a[i]);
    for i:=1 to m do
     begin
       read(c[i]);
       b[c[i]]:=1;
     end;
    sort(1,n);
    k:=0;
    for i:=1 to n do
     begin
       if b[i]=0 then k:=k+a[i];
     end;
    for i:=1 to n do
     begin
       if b[i]=1 then k:=k+max(a[i],k);
     end;
    writeln(k);

  end.