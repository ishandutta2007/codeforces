uses math;
var n,m,i,j,k,ans,l,r,ans1,ans2:longint;
    a:array[1..8,1..8]of char;
  begin
    n:=8;
    for i:=1 to n do
     begin
       for j:=1 to n do
        read(a[i,j]);
       readln;
     end;
    ans1:=9;
    ans2:=9;
    for i:=1 to n do
     for j:=1 to n do
      if a[i,j]='W' then
       begin
         k:=0;
         for l:=i-1 downto 1 do
          if a[l,j]<>'.' then k:=1;
         if k=0 then ans1:=min(ans1,i-1);
       end else
      if a[i,j]='B' then
       begin
         k:=0;
         for l:=i+1 to n do
          if a[l,j]<>'.' then k:=1;
         if k=0 then ans2:=min(ans2,n-i);
       end;
    if ans1<=ans2 then writeln('A') else writeln('B');
  end.