var a:array[1..1000] of longint;
    n,m,x,y,i,j:longint;
begin
  readln(n,m);
  fillchar(a,sizeof(a),0);
  for i:=1 to m do
    begin
      readln(x,y);
      for j:=x to y do inc(a[j]);
    end;
  for i:=1 to n do
    begin
      if a[i]=0 then
        begin
          writeln(i,' 0');halt;
        end;
      if a[i]>1 then
        begin
          writeln(i,' ',a[i]);halt;
        end;
    end;
  writeln('OK');
end.