var n,x,m,y,t,i,m1,m2,m3:longint;
    s:int64;
function solve(x,r,y:longint):longint;
  var s,m1,m2:longint;
  begin
    s:=0;
    if r<=y-x then
      begin
        m1:=y-x-r+1;m2:=y-x+r-1;
      end else
      begin
        m1:=r+x-y;m2:=r-x+y-1;
      end;
    if m2>m then m2:=m;
    if m1<1 then m1:=1;
    if m2>=m1 then inc(s,(m2-m1+1) shl 1) else inc(s);
    solve:=s;
  end;
begin
  readln(n,x,m,y);
  if x>y then
    begin
      t:=n;n:=m;m:=t;
      t:=x;x:=y;y:=t;
    end;
  s:=1;
  for i:=1 to n do inc(s,solve(x,i,y));
  if m>=x+n-y+1 then
    if x+n-y+1<1 then inc(s,m) else inc(s,m-x-n+y);
  writeln(s);
end.