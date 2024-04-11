var n,m,i,j,k,ans,l,r:longint;
    a,b:array[1..8]of longint;
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
    for i:=1 to 8 do
     read(a[i],b[i]);
    sort(1,8);
    if (a[1]=a[2]) and (a[2]=a[3]) and (a[3]<a[4]) and (a[4]=a[5]) and
    (a[5]<a[6]) and (a[6]=a[7]) and (a[7]=a[8]) and (b[1]<b[2]) and
    (b[2]<b[3]) and (b[4]=b[1]) and (b[5]=b[3]) and (b[6]=b[1]) and
    (b[7]=b[2]) and (b[8]=b[3]) then writeln('respectable') else
    writeln('ugly');
 
  end.