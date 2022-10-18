var n,m,i,j,k,l,r:longint;
    a,b,c:array[1..100]of longint;
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
    for i:=1 to n do
     read(a[i]);
    read(m);
    for i:=1 to m do
     read(b[i]);
    sort(1,n);
    c:=b;
    b:=a;
    a:=c;
    sort(1,m);
    c:=a;
    a:=b;
    b:=c;
    k:=1;
    l:=0;
    for i:=1 to n do
     begin
       for j:=k to m do
        if abs(a[i]-b[j])<=1 then begin l:=l+1; k:=j+1; break; end;
     end;
    writeln(l);
  end.