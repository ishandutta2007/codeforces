var g:array[1..100,1..100] of longint;
    n,m,i,j,a,b,s,t:longint;
function chk(x1,x2,y1,y2:longint):longint;
  var i,j,s:longint;
  begin
    s:=0;
    for i:=x1 to x2 do
      for j:=y1 to y2 do
        inc(s,g[i,j]);
    chk:=s;
  end;
begin
  readln(n,m);
  for i:=1 to n do
    for j:=1 to m do read(g[i,j]);
  readln(a,b);s:=maxlongint;
  for i:=1 to n-a+1 do
    for j:=1 to m-b+1 do
      begin
        t:=chk(i,i+a-1,j,j+b-1);
        if t<s then s:=t;
      end;
  for i:=1 to n-b+1 do
    for j:=1 to m-a+1 do
      begin
        t:=chk(i,i+b-1,j,j+a-1);
        if t<s then s:=t;
      end;
  writeln(s);
end.