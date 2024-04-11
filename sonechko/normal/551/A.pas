var n,m,i,j,k,ans,l,r:longint;
    a,b,c:array[0..2000]of longint;
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
    read(n);
    for i:=1 to n do
     begin
      b[i]:=i;
      read(a[i]);
     end;
    sort(1,n);
    for i:=1 to n do
     if (i>1) and (a[i]=a[i-1]) then c[b[i]]:=c[b[i-1]] else c[b[i]]:=i;
    for i:=1 to n do
     write(c[i],' ');
    writeln;
  end.