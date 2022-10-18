Var n,i,sum1,sum2:longInt;
    a:array[1..10000] of LongInt;
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
  read(n);
  for i:= 1 to n do
   read(a[i]);
  sort(1,n);
  if n mod 2=0 then
  for i:= 1 to n do
   begin
    if i mod 2<>0 then sum1:=sum1+a[i]
                  else sum2:=sum2+a[i];
   end
               else
  For i:= n downto 1 do
   Begin
    if sum1<sum2 then sum1:=sum1+a[i]
                   else sum2:=sum2+a[i];
   end;
  if sum1=sum2 then writeLn('YES')
               else writeLn('NO');
 end.