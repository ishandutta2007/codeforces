uses math;
var n,m,k,ans,l,r:int64;       i,j:longint;
    a,b,s:array[0..1000000]of int64;
procedure sort(l,r: longint);
      var
         i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=a[l+random(r-l+1)];
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
    read(n,m);
    for i:=1 to n do
     read(a[i],b[i]);
    sort(1,n);
    for i:=1 to n do
     s[i]:=s[i-1]+b[i];
    for i:=1 to n do
     begin
       l:=i;
       r:=n;
       while (l+1<r) do
        begin
          k:=(L+r) div 2;
          if (a[k]-a[i]<m) then l:=k else r:=k;
        end;
       if a[r]-a[i]<m then ans:=max(ans,s[r]-s[i-1]) else
       ans:=max(ans,s[l]-s[i-1]);
     end;
    writeln(ans);
  end.