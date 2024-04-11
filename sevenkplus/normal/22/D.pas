var x,y,p:array[1..1000] of longint;
    c:array[1..1000] of boolean;
    n,i,j,t:longint;
begin
  readln(n);
  for i:=1 to n do readln(x[i],y[i]);
  for i:=1 to n do
    if x[i]>y[i] then
      begin
        t:=x[i];x[i]:=y[i];y[i]:=t;
      end;
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if y[i]>y[j] then
        begin
          t:=x[i];x[i]:=x[j];x[j]:=t;
          t:=y[i];y[i]:=y[j];y[j]:=t;
        end;
  fillchar(c,sizeof(c),false);
  t:=0;
  for i:=1 to n do
    if not c[i] then
      begin
        inc(t);p[t]:=y[i];
        for j:=1 to n do
          if (x[j]<=y[i]) and (y[j]>=y[i]) then c[j]:=true;
      end;
  writeln(t);
  for i:=1 to t-1 do write(p[i],' ');writeln(p[t]);
end.