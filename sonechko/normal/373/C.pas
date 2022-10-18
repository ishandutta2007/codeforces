var i,j,m,n:longint;
    a:array[0..1000001] of longint;
    b:array[0..1000001] of boolean;
  procedure sort(l,r: longint);
      var
         i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=a[(l+r)div 2];
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
    read(a[i]);
   for i:=1 to n do
    b[i]:=true;
   sort(1,n);
   m:=n;
   j:=n div 2+1;
   for i:=1 to n do
    if b[i] then
     begin
      if (j<=i) then j:=i+1;
      while (a[i]*2>a[j]) or not(b[j]) do
       begin
        if (j>n) then break;
        inc(j);
       end;
      if (j>n) then break;
      b[j]:=false;
      dec(m);
      inc(j);
     end;
   writeln(m);
  end.