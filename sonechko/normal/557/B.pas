var n,m,i,j,k,ans,l,r,x,y:longint;
    a:array[0..200000]of longint;
    p:extended;
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
  begin
   read(n,m);
   for i:=1 to n*2 do
    read(a[i]);
   sort(1,n*2);
   p:=m/(3*n);
   if a[1]<p then p:=a[1];
   if a[n+1]<p*2 then p:=a[n+1]/2;
   writeln(p*3*n:0:9);
  end.