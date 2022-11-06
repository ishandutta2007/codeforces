
program ditry3;
uses math;

var
    a:array[0..1020,0..1020] of boolean;
    i,j,k,l,m,n,x,y,x0,y0,ans:longint;
    ch:char;
    f:boolean;

procedure check(x,y,p,q:longint);
var
    i,j:longint;
    b:array[0..1020,0..1020] of boolean;
    g:boolean;
begin
  for i:= 1 to n do
    for j:= 1 to m do
      b[i,j]:=a[i,j];
  for i:= x to x+p-1 do
    for j:= y to y+q-1 do
      if (b[i,j]) then b[i,j]:=false else exit;
  g:=false;
  repeat
    if (a[x+p,y]) and (a[x,y+q]) then exit;
    if (a[x+p,y]) then begin
      for i:= y to y+q-1 do
        if (b[x+p,i]) then b[x+p,i]:=false else exit;
      inc(x);
    end else
    if (a[x,y+q]) then begin
      for i:= x to x+p-1 do
        if (b[i,y+q]) then b[i,y+q]:=false else exit;
      inc(y);
    end else g:=true;
  until g;
  for i:= 1 to n do
    for j:= 1 to m do
      if b[i,j] then g:=false;
  if g then begin ans:=min(ans,p*q); f:=true end;
end;

begin
  readln(n,m);
  fillchar(a,sizeof(a),false);
  for i:= 1 to n do
    begin
      for j:= 1 to m do
        begin
          read(ch);
          if ch='X' then a[i,j]:=true;
        end;
      readln;
    end;
  i:=1;
  j:=1;
  while not(a[i,j]) do
    if j<m then inc(j) else begin j:=1; inc(i) end;
  x:=i;y:=j;
  repeat
    inc(i);
  until a[i,y]=false;
  repeat
    inc(j);
  until a[x,j]=false;
  x0:=i-x;y0:=j-y;
  i:=x;j:=y;
  f:=false;ans:=maxlongint;
  while (a[x+x0-1,j]) and not(a[x+x0,j]) do inc(j);
  while (a[i,y+y0-1]) and not(a[i,y+y0]) do inc(i);
  if y0-j+y>0 then check(x,y,x0,y0-j+y)
              else check(x,y,x0,1);
  if x0-i+x>0 then check(x,y,x0-i+x,y0)
              else check(x,y,1,y0);
  if f then writeln(ans) else writeln('-1');
end.