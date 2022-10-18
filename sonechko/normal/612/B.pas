var n,m,j,k,ans,l,r:int64; i:longint;
    a,b:array[1..10000000]of int64;
  begin
    read(n);
    for i:=1 to n do
     begin
       read(l);
       b[l]:=i;
     end;
    for i:=2 to n do
     ans:=ans+abs(b[i]-b[i-1]);
    writeln(ans);
  end.