var n,m,i,j,k,ans,l,r:longint;
    a:array[1..1000]of longint;
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
    sort(2,n);
    k:=2;
    while a[1]<=a[k] do
     begin
       dec(a[k],1);
       inc(a[1],1);
       inc(ans);
       if (k=n) then k:=2 else
       if (a[k+1]=a[k]+1) then inc(k) else k:=2;
     end;
    writeln(ans);
  end.