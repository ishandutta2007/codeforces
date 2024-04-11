var n,m,i,j,k,l,r,l1,r1:longint;
    a,b,c:array[1..2000]of longint;
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
                y:=b[i];
                b[i]:=b[j];
                b[j]:=y;
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
      b[i]:=i;
     end;
    sort(1,n);
    k:=0;
    for i:=2 to n do
     if a[i]=a[i-1] then begin inc(k); if k=1 then begin l:=i; r:=i-1; end
     else begin l1:=i; r1:=i-1; end; end;
    if k<2 then writeln('NO') else
     begin
       writeln('YES');
       for i:=1 to n do
        write(b[i],' ');
       writeln;
       k:=b[l];
       b[l]:=b[r];
       b[r]:=k;
       for i:=1 to n do
        write(b[i],' ');
       writeln;
       k:=b[r];
       b[r]:=b[l];
       b[l]:=k;
       k:=b[l1];
       b[l1]:=b[r1];
       b[r1]:=k;
       for i:=1 to n do
        write(b[i],' ');
       writeln;
     end;
  end.