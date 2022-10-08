var a:array[1..100] of longint;
    n,i,l,j,s,t,m:longint;
begin
  readln(n,l);m:=0;
  for i:=1 to n do
    begin
      read(a[i]);if a[i]>m then m:=a[i];
    end;
  t:=0;
  for j:=l to m do
    begin
      s:=0;
      for i:=1 to n do inc(s,a[i] div j);
      if s*j>t then t:=s*j;
    end;
  writeln(t);
end.