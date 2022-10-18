
var n,m,i,j,k,ans,l,r:longint;
    a:array[1..100000]of longint;
procedure sort(l,r: longint);
      var
         i,j,x,y,k: longint;
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
     read(a[i]);
    sort(1,n);
    l:=0;
    for i:=1 to n do
     if a[i]>=l then begin l:=l+a[i]; ans:=ans+1; end;
    writeln(ans);
  end.