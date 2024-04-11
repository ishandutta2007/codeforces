const big=1e+9;
var n,i:longint;
    v,t:array[0..200000] of longint;
    last,ans,q,e,d,p,a,c:extended;
begin
  readln(n,a,d);
  for i:=1 to n do
    readln(t[i],v[i]);
  last:=-big;
  for i:=1 to n do
    begin
      c:=v[i]/a;
      q:=v[i]*c/2;
      if q<=d then
        begin
          e:=d-q;
          ans:=t[i]+c+e/v[i];
        end
      else
        begin
          p:=sqrt(d*a*2);
          ans:=t[i]+p/a;
        end;
      if ans<last then ans:=last;
      last:=ans;
      writeln(ans:0:10);
    end;
end.