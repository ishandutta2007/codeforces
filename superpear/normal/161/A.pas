var a,b,xx,yy:array[0..300000] of longint;
    n,m,i,x,y,p,ans:longint;

begin
  randomize;

  readln(n,m,x,y);
  for i:=1 to n do read(a[i]);
  for i:=1 to m do read(b[i]);
  p:=1;
  ans:=0;
  for i:=1 to m do
    begin
      while (p<=n) and (a[p]<b[i]-y) do inc(p);
      if p>n then break;
      if a[p]<=b[i]+x then
        begin
          inc(ans);
          xx[ans]:=p;yy[ans]:=i;
          inc(p);
        end;
    end;
  writeln(ans);
  for i:=1 to ans do writeln(xx[i],' ',yy[i]);
end.