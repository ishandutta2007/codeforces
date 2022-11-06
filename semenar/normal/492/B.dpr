program Fonari;
var n, l, i, ansx2: integer;
pos: array [1..1000] of integer;
ans: real;

function max(a,b:integer):integer;
begin
if a>b then max:=a else max:=b;
end;

procedure sort(lc, rc: integer);
var l, r, x, c: integer;
begin
l := lc;
r := rc;
x := pos[(l+r) div 2];
while l<r do
  begin
  while pos[l] < x do l := l+1;
  while pos[r] > x do r := r-1;
  if l<=r then
    begin
    c := pos[l];
    pos[l] := pos[r];
    pos[r] := c;
    l := l+1;
    r := r-1;
    end;
  end;
if (l < rc) then sort(l,rc);
if (r > lc) then sort(lc,r);
end;

begin
  readln(n, l);
  for i:=1 to n do read(pos[i]);
  sort(1,n);
  ansx2 := 2*max(pos[1], l-pos[n]);
  for i:=1 to n-1 do if (pos[i+1]-pos[i]) > ansx2 then ansx2 := pos[i+1]-pos[i];
  ans := ansx2/2;
  writeln(ans);
end.