var n,m,i,j,k,l,r:longint;
    b:array[1..100000]of longint;
    a,ans:array[1..100000]of string;
    s:string;
procedure sort(l,r: longint);
      var
         i,j,z,w: longint;
         x,y:string;
      begin
         i:=l;
         j:=r;
         x:=a[(l+r) div 2];
         z:=b[(l+r) div 2];
         repeat
           while (a[i]<x) or ((a[i]=x) and (b[i]<z)) do
            inc(i);
           while (x<a[j]) or ((x=a[j]) and (z<b[j])) do
            dec(j);
           if not(i>j) then
             begin
                y:=a[i];
                a[i]:=a[j];
                a[j]:=y;
                w:=b[i];
                b[i]:=b[j];
                b[j]:=w;
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
    readln(n);
    for i:=1 to n do
     begin
       readln(a[i]);
       b[i]:=i;
     end;
    sort(1,n);
    ans[b[1]]:='OK';
    l:=0;
    for i:=2 to n do
     if a[i]=a[i-1] then begin inc(l); str(l,s); ans[b[i]]:=a[i]+s; end else
      begin l:=0; ans[b[i]]:='OK';      end;
    for i:=1 to n do
     writeln(ans[i]);

  end.