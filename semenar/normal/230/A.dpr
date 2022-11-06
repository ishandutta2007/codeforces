program DungeonsAndDragons;
var s, n, i: integer;
ans: string;
xi, yi: array [1..10000] of integer;

procedure qs(lc,rc:integer);
var x, l, r, tmp: integer;
begin
x:=xi[lc+((rc-lc) div 2)];
l:=lc;
r:=rc;
while l<=r do
  begin
  while xi[l]<x do l:=l+1;
  while xi[r]>x do r:=r-1;
  if l<=r then
    begin
    tmp:=xi[l];
    xi[l]:=xi[r];
    xi[r]:=tmp;
    tmp:=yi[l];
    yi[l]:=yi[r];
    yi[r]:=tmp;
    l:=l+1;
    r:=r-1;
    end;
  end;
if (l<rc) then qs(l,rc);
if (r>lc) then qs(lc,r);
end;

begin
readln(s,n);
for i:=1 to n do
  readln(xi[i],yi[i]);
qs(1,n);
ans:='YES';
for i:=1 to n do
  if s>xi[i] then s:=s+yi[i] else ans:='NO';
writeln(ans);
end.