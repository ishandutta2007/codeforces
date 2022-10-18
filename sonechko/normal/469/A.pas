var n,i,j,k,l,r:longint;
   a:array[1..1000]of longint;
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
    read(l);
    for i:=1 to l do
     read(a[i]);
    read(r);
    for i:=1 to r do
     begin
       inc(l);
       read(a[l]);
     end;
    sort(1,l);
    r:=1;
    k:=0;
    for i:=1 to l do
     begin
     if a[i]=r then inc(r) else
     if a[i]>r then k:=1;
     if r=n+1 then break;
     end;
    if (k=0) and (r=n+1) then writeln('I become the guy.') else writeln('Oh, my keyboard!');

  end.