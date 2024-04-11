var n,m,i,j,k,ans,l,r:longint;
    a,b,c:array[1..100000]of longint;
procedure sort(l,r: longint);
      var
         i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=a[(l+r) div 2];
         repeat
           while a[i]<x do
            inc(i);
           while x<a[j] do
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
procedure sort1(l,r: longint);
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
                y:=b[i];
                b[i]:=b[j];
                b[j]:=y;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           sort1(l,j);
         if i<r then
           sort1(i,r);
      end;
  begin
    read(n);
    for i:=1 to n do
     read(a[i]);
    sort(1,n);
    for i:=1 to n-1 do
     read(b[i]);
    sort1(1,n-1);
    for i:=1 to n do
     if a[i]<>b[i] then begin l:=a[i]; break; end;
    for i:=1 to n-2 do
     read(a[i]);
    sort(1,n-2);
    a[n-1]:=0;
    for i:=1 to n-1 do
     if b[i]<>a[i] then begin r:=b[i]; break; end;
    writeln(l);writeln(r);
  end.