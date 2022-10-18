var n,m,k,l,r:int64;
    i,j:longint;
    a:Array[1..100000]of longint;
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
    read(n,l);
    for I:=1 to n do
     read(a[i]);
    sort(1,n);
    r:=0;
    for i:=1 to n do
     begin
       r:=r+(a[i]*l);
       if l>1 then l:=l-1;
     end;
    writeln(r);
  end.