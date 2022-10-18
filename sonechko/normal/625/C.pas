var n,m,i,j,k,ans,l,r:longint;
    a:array[1..500,1..500]of longint;
  begin
    read(n,m);
    l:=n*n;
    for i:=1 to n do
     begin
       for j:=n downto m do
        begin
          a[i,j]:=l;
          l:=l-1;
        end;
       ans:=ans+l+1;
     end;
    for i:=1 to n do
     begin
       for j:=m-1 downto 1 do
        begin
          a[i,j]:=l;
          l:=l-1;
        end;
     end;
    writeln(ans);
    for i:=1 to n do
     begin
       for j:=1 to n do
        write(a[i,j],' ');
       writeln;
     end;
  end.