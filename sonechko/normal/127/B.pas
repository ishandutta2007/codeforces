var n,m,i,j,k,ans,l,r:longint;
    b:array[1..100]of longint;
  begin
    read(n);
    for i:=1 to n do
     begin
       read(l);
       b[l]:=b[l]+1;
     end;
    for i:=1 to 100 do
     ans:=ans+b[i] div 2;
    writeln(ans div 2);
  end.