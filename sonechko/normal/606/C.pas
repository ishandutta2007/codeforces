uses math;
var n,m,i,j,k,l,r,ans:Longint;
    a,b:array[1..100000]of longint;
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
    l:=1;
    for i:=2 to n do
     if b[i]>b[i-1] then inc(l) else begin if l>ans then ans:=l; l:=1; end;
    if l>ans then ans:=l;
    writeln(n-ans);
  end.