const big=100000000000000000;

var n,i,t,j,v:longint;
    k,c:array[0..300] of longint;
    p:array[0..300] of int64;
    ans,dq:int64;

procedure swap(var a,b:longint);
  var r:longint;
  begin
    r:=a;
    a:=b;
    b:=r;
  end;

begin
  readln(n);
  for i:=1 to n do
    readln(k[i],c[i]);
  readln(t);
  for i:=1 to t do
    read(p[i]);
  p[t+1]:=big;
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if c[i]>c[j] then
        begin
          swap(c[i],c[j]);
          swap(k[i],k[j]);
        end;
  v:=1;
  ans:=0;
  dq:=0;
  for i:=1 to n do
    begin
      while int64(dq)+k[i]>p[v] do
        begin
          ans:=ans+(int64(p[v])-dq)*int64(v)*c[i];
          k[i]:=k[i]-(int64(p[v])-dq);
          dq:=p[v];
          inc(v);
        end;
      ans:=ans+int64(k[i])*v*c[i];
      dq:=dq+k[i];
    end;
  writeln(ans);
end.