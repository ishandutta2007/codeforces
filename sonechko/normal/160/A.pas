var n,m,i,j,k,l,r:longint;
    a:array[1..100]of longint;
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
     read(a[i]);
    sort(1,n);
    l:=0;
    for i:=1 to n do
     l:=l+a[i];
    r:=0;
    for i:=1 to n do
     begin
       l:=l-a[i];
       r:=r+a[i];
       if r>l then begin writeln(i); halt; end;
     end;
  end.