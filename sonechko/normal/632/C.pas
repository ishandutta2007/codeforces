var n,m,i,j,k,ans,l,r:longint;
    a:array[1..100000]of string;
procedure sort(l,r: longint);
      var
         i,j,k: longint;
         x,y:string;
      begin
         i:=l;
         j:=r;
         k:=random(r-l+1)+l;
         x:=a[k];
         repeat
           while (a[i]+x<x+a[i]) do
            inc(i);
           while (x+a[j]<a[j]+x) do
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
    readln(n);
    for i:=1 to n do
     readln(a[i]);
    sort(1,n);
    for i:=1 to n do
     write(a[i]);
    writeln;
  end.