var n,m,i,j,k,ans,l,r:longint;
    a:array[1..100000]of longint;
  begin
    read(n);
    for i:=1 to n do
     begin
       read(l);
       while (l mod 2=0) or (l mod 3=0) do
        begin
          if l mod 2=0 then l:=l div 2 else
          if l mod 3=0 then l:=l div 3;
        end;
       a[i]:=l;
     end;
    for i:=2 to n do
     if a[i]<>a[i-1] then begin writeln('No'); halt; end;
    writeln('Yes');
  end.