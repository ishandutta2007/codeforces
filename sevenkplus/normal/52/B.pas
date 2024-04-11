var a:array[1..1000,1..1000] of char;
    x,y:array[1..1000] of longint;
    n,m,i,j:longint;
    s:int64;
begin
  fillchar(x,sizeof(x),0);
  fillchar(y,sizeof(y),0);
  readln(n,m);
  for i:=1 to n do
    begin
      for j:=1 to m do 
        begin
          read(a[i,j]);
          if(a[i,j]='*') then
            begin
              inc(x[i]);inc(y[j]);
            end;
        end;
      readln;
    end;
  s:=0;
  for i:=1 to n do 
    for j:=1 to m do
      if(a[i,j]='*') then 
        inc(s,(x[i]-1)*(y[j]-1));
  writeln(s);
end.