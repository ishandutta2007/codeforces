var n,m,j,k,ans,l,r,b,p,t,g,d:int64;
i:longint;
    a:array[1..100000]of int64;
procedure sort(l,r: longint);
      var
         i,j,x,y,k: int64;
      begin
         i:=l;
         j:=r;
         k:=random(r-l+1)+l;
         x:=a[k];
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
  for i:=1 to n do
   begin
    read(a[i]);
    if a[i] mod 2=1  then  k:=k+1;
    ans:=ans+a[i];
   end;
  sort(1,n);
  if k mod 2=0 then writeln(ans) else
   begin
     for i:=1 to n do
      if a[i] mod 2=1 then begin ans:=ans-a[i]; writeln(ans); halt; end;
   end;
end.