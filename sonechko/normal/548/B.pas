var n,m,i,j,k,ans,l,r,c:longint;
    a:array[1..500,1..500]of longint;
    b:array[1..500]of longint;
  begin
    read(n,m,k);
    for i:=1 to n do
     for j:=1 to m do
      read(a[i,j]);
    for i:=1 to n do
     begin
       l:=0;
       b[i]:=0;
       for j:=1 to m do
        if a[i,j]=1 then inc(l) else
        begin
          if l>b[i] then b[i]:=l;
          l:=0;
        end;
       if l>b[i] then b[i]:=l;
     end;
    for i:=1 to k do
     begin
       read(l,r);
       a[l,r]:=1-(a[l,r]);
       b[l]:=0;
       c:=0;
       b[l]:=0;
       for j:=1 to m do
        if a[l,j]=1 then inc(c) else
        begin
          if c>b[l] then b[l]:=c;
          c:=0;
        end;
       if c>b[l] then b[l]:=c;
       ans:=0;
       for j:=1 to n do
        if b[j]>ans then ans:=b[j];
       writeln(ans);
     end;

  end.