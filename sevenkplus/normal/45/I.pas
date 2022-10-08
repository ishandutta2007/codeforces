var a:array[1..100] of longint;
    n,i,s,t,p:longint;
begin
  readln(n);s:=0;t:=0;p:=0;
  for i:=1 to n do
    begin
      read(a[i]);
      if a[i]<0 then
        begin
          inc(s);if (p=0) or (a[i]>a[p]) then p:=i;
        end;
      if a[i]>0 then inc(t);
    end;
  if t=0 then
    begin
      if (n-t-s>0) and (s<2) then
        begin
          writeln(0);halt;
        end;
      if (n-t-s=0) and (s=1) then
        begin
          writeln(a[1]);halt;
        end;
    end;
  if not odd(s) then p:=0;
  for i:=1 to n do
    if (a[i]<>0) and (i<>p) then write(a[i],' ');
end.