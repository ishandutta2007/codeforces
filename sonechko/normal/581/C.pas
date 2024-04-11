uses math;
var n,m,i,j,k,ans,l,r:longint;
    a,b:array[1..100000]of longint;
procedure sort(l,r: longint);
      var
         i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=b[l+random(r-l+1)];
         repeat
           while b[i]<x do
            inc(i);
           while x<b[j] do
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
     begin
      read(a[i]);
      b[i]:=10-(a[i] mod 10);
     end;
    sort(1,n);
    for i:=1 to n do
     if (m>=b[i]) and (a[i]<100) then begin m:=m-b[i]; a[i]:=a[i]+b[i]; end else break;
    for i:=1 to n do
     if a[i]<100 then
      begin
        if m<10 then break;
        k:=min((100-a[i])div 10,m div 10)*10;
        m:=m-k;
        a[i]:=a[i]+k;
      end;
    for i:=1 to n do
     ans:=ans+a[i] div 10;
    writeln(ans);
  end.