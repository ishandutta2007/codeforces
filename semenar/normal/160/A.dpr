program Blitz;
var n, i, sum, all, k: integer;
coins: array [1..100] of integer;

procedure qs(l,r: integer);
var lc, rc, x, tmp: integer;
begin
x := coins[l+((r-l) div 2)];
lc := l;
rc := r;
while lc <= rc do
  begin
  while coins[lc] > x do lc:=lc+1;
  while coins[rc] < x do rc:=rc-1;
  if lc <= rc then
    begin
    tmp := coins[lc];
    coins[lc] := coins[rc];
    coins[rc] := tmp;
    lc := lc+1;
    rc := rc-1;
    end;
  end;
if rc>l then qs(l,rc);
if lc<r then qs(lc,r);
end;

begin
readln(n);
all := 0;
for i:=1 to n do 
  begin
  read(coins[i]);
  all := all+coins[i];
  end;
qs(1,n);
k := 0;
sum := 0;
while 2*sum <= all do
  begin
  sum := sum+coins[k+1];
  k:=k+1;
  end;
writeln(k);
end.