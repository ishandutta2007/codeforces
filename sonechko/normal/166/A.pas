var n,m,i,j,k,l,r:longint;
    a,b:array[1..1000]of longint;
 procedure sort(l,r: longint);
      var
         i,j,x,y,z: longint;
      begin
         i:=l;
         j:=r;
         x:=a[(l+r) div 2];
         z:=b[(l+r) div 2];
         repeat
           while (a[i]>x) or ((a[i]=x) and (b[i]<z)) do
            inc(i);
           while (x>a[j]) or ((x=a[j]) and (z<b[j])) do
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
     read(a[i],b[i]);
    sort(1,n);
    for i:=1 to n do
     if (a[i]=a[m]) and (b[i]=b[m]) then inc(l);
    writeln(l);
  end.