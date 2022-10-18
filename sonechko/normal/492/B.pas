var a,b,c:array [1..100000] of extended;
    x,y,z,j,n,m,l,e:int64;
    i:longint;
    d:extended;
 procedure sort(l,r: longint);
      var
         i,j: longint;
         x,y:extended;
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
  begin
     read(n,l);
     for i:=1 to n do
      read(a[i]);
     sort(1,n);
     if (a[1]<>0) then d:=a[1];
     if (a[n]<>l) then
     if (l-a[n]>d) then d:=l-a[n];
     for I:=2 to n do
      begin
       if (a[i]-a[i-1])/2>d then d:=(a[i]-a[i-1])/2;
      end;
     writeln(d:0:9);
  end.