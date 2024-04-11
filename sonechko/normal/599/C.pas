uses math;
var n,m,i,j,k,ans,l,r:longint;
    a,b,c,d,g:array[1..1000000]of longint;
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
                y:=d[i];
                d[i]:=d[j];
                d[j]:=y;
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
    ans:=maxlongint;
    for i:=1 to n do
     begin
      read(a[i]);
      d[i]:=i;
     end;
    b:=a;
    sort(1,n);
    l:=1;
    b[d[1]]:=l;
    g[l]:=l;
    for i:=1 to n do
     begin
       if a[i]<>a[i-1] then begin inc(l); g[l]:=i; end;
       b[d[i]]:=l;
     end;
    k:=0;
    ans:=0;
    for i:=1 to n do
     if i>k then
      begin
        inc(ans);
        k:=g[b[i]];
        inc(g[b[i]]);
      end else begin k:=max(k,g[b[i]]); inc(g[b[i]]); end;
    writeln(ans);

  end.