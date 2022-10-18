var n,m,i,j,k,ans,l,r:longint;
    a,b,next,last,d,ans1,ans2,g:array[-100000..100000]of longint;

procedure sort1(l,r: longint);
      var
         i,j,x,y,z: longint;
      begin
         i:=l;
         j:=r;
         x:=a[(l+r) div 2];
         z:=b[(l+r) div 2];
         repeat
           while (a[i]<x) or ((a[i]=x) and (b[i]<z)) do
            inc(i);
           while (x<a[j]) or ((a[j]=x) and (z<b[j])) do
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
           sort1(l,j);
         if i<r then
           sort1(i,r);
      end;
  begin
    read(n);
    for i:=1 to n do
     begin
      read(a[i],b[i]);
     end;
    sort1(1,n);
    for i:=1 to n do
     begin
       next[last[b[i]-a[i]]]:=i;
       if d[b[i]-a[i]]=0 then d[b[i]-a[i]]:=i;
       last[b[i]-a[i]]:=i;
     end;
    for i:=1 to n do
     begin
      read(l);
      if (d[l]=0) then begin writeln('NO'); halt; end;
      ans1[i]:=a[d[l]];
      ans2[i]:=b[d[l]];
      g[d[l]]:=i;
      d[l]:=next[d[l]];
     end;
    for i:=2 to n do
     if (b[i]>=b[i-1]) and (g[i]<g[i-1]) then begin writeln('NO'); halt; end;
    {for i:=2 to n do
     if (ans1[i]>=ans1[i-1]) or (ans2[i]>=ans2[i-1]) then else
      begin writeln('NO'); halt; end;  }
    writeln('YES');
    for i:=1 to n do
     writeln(ans1[i],' ',ans2[i]);
  end.