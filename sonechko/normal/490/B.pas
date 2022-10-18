var s:ansistring;
    i,j,k,l,r,n,m:longint;
    a,b,ans:array[0..1000010]of longint;
  begin
    read(n);
    for i:=0 to 1000000 do
     begin a[i]:=-1; b[i]:=-1; end;
    for i:=1 to n do
     begin
      read(l,r);
      a[l]:=r;
      b[r]:=l;
     end;
    for i:=1 to 1000000 do
     if (a[i]<>-1) and (b[i]=-1) then begin l:=i; break; end;
   k:=1;
   while k<=n do
     begin
       ans[k]:=l;
       l:=a[l];
       inc(k,2);
     end;
   l:=0;
   k:=0;
   while k<=n do
    begin
      ans[k]:=l;
      l:=a[l];
      inc(k,2);
    end;
   for i:=1 to n do
    write(ans[i],' ');
   writeln;
  end.
  3 2
  0 1
  2 0
  1 4
 
 
 
0 1             0 2
1 4             1 0
2 0             2 3                       0 3 1 2 4 0
3 2             3 -
4 -             4 1