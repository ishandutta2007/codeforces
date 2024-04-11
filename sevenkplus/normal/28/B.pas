var a,b:array[1..110,1..110] of boolean;
    p,w:array[1..110] of longint;
    n,i,j,k:longint;
begin
  readln(n);
  for i:=1 to n do read(p[i]);
  for i:=1 to n do read(w[i]);
  fillchar(a,sizeof(a),false);
  fillchar(b,sizeof(b),false);
  for i:=1 to n do
    if p[i]<>i then
      begin
        b[i,p[i]]:=true;b[p[i],i]:=true;
      end;
  for i:=1 to n do
    begin
      if i-w[i]>=1 then
        begin
          a[i-w[i],i]:=true;a[i,i-w[i]]:=true;
        end;
      if i+w[i]<=n then
        begin
          a[i+w[i],i]:=true;a[i,i+w[i]]:=true;
        end;
    end;
  for k:=1 to n do
    for i:=1 to n do if a[i,k] then
      for j:=1 to n do if a[k,j] then a[i,j]:=true;
  for i:=1 to n do
    for j:=1 to n do
      if b[i,j] and not a[i,j] then
        begin
          writeln('NO');halt;
        end;
  writeln('YES');
end.