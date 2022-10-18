var n,m,i,j,k,ans,l,r:longint;
    a,b:array[1..20]of longint;
procedure sort(l,r: longint);
      var
         i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=a[(l+r) div 2];
         repeat
           while a[i]>x do
            inc(i);
           while x>a[j] do
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
    for i:=1 to m do
     read(b[i],a[i]);
    sort(1,m);
    ans:=0;
    for i:=1 to m do
     if n>b[i] then begin ans:=ans+b[i]*a[i]; n:=n-b[i]; end else
      begin ans:=ans+n*a[i]; break; end;
    writeln(ans);
  end.