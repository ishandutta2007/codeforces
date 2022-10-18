var n,m,i,j,k,ans,l,r:Longint;
    a,b:array[1..5000]of longint;
procedure sort(l,r: longint);
      var
         i,j,x,y,z: longint;
      begin
         i:=l;
         j:=r;
         x:=a[(l+r) div 2];
         z:=b[(l+r) div 2];
         repeat
           while (a[i]<x) or ((a[i]=x) and (b[i]<z)) do
            inc(i);
           while (x<a[j]) or ((x=a[j]) and (z<b[j])) do
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
    read(n);
    for i:=1 to n do
     read(a[i],b[i]);
    sort(1,n);
    l:=b[1];
    for i:=2 to n do
     if b[i]>=l then l:=b[i] else l:=a[i];
    writeln(l);
  end.