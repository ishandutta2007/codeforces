var n,m,i,j,k,l,r,p:Longint;
    a,b,c:array[0..801,0..801]of longint;
    d,e,ans:array[0..801]of longint;
 procedure sort(l,r: longint);
      var
         i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=a[p,(l+r) div 2];
         repeat
           while a[p,i]>x do
            inc(i);
           while x>a[p,j] do
            dec(j);
           if not(i>j) then
             begin
                y:=a[p,i];
                a[p,i]:=a[p,j];
                a[p,j]:=y;
                y:=b[p,i];
                b[p,i]:=b[p,j];
                b[p,j]:=y;
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
    for i:=2 to n*2 do
     begin
       for j:=1 to i-1 do
        begin
          read(a[i,j]);
          a[j,i]:=a[i,j];
        end;
     end;
    for i:=1 to 2*n do
     for j:=1 to 2*n do
      b[i,j]:=j;
    c:=a;
    for p:=1 to 2*n do
     sort(1,2*n);
    for i:=1 to n*2 do
     d[i]:=1;
    for p:=1 to n do
     begin
       for i:=1 to 2*n do
        if a[i,d[i]]=a[b[i,d[i]],d[b[i,d[i]]]] then
         begin
           e[i]:=1;
           e[b[i,d[i]]]:=1;
           ans[i]:=b[i,d[i]];
           ans[b[i,d[i]]]:=i;
           break;
         end;
       for i:=1 to n*2 do
        while e[b[i,d[i]]]=1 do
         inc(d[i]);
     end;
    for i:=1 to n*2 do
     write(ans[i],' ');writeln;
  end.