var n,m,i,j,k,l,r:longint;
    a,b:array[1..100000]of longint;
procedure sort(l,r: longint);
      var
         i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=b[(l+r) div 2];
         repeat
           while b[i]<x do
            inc(i);
           while x<b[j] do
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
    for I:=1 to n do
     read(a[i],b[i]);
    sort(1,n);
    for i:=2 to n do
     if a[i]<a[i-1] then
      begin
        for j:=i-1 downto 1 do
         if (b[j]<>B[I]) THEN begin writeln('Happy Alex'); halt; end;
      end;
    writeln('Poor Alex');
  end.