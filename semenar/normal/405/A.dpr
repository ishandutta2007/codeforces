program QuickSort;
var n, i: integer;
blocks: array [1..100] of integer;

procedure qs(lc,rc:integer);
var x, l, r, tmp:integer;
begin
x:=blocks[lc+((rc-lc) mod 2)];
l:=lc;
r:=rc;
while l<=r do
  begin
  while blocks[l]<x do l:=l+1;
  while blocks[r]>x do r:=r-1;
  if l<=r then
    begin
    tmp:=blocks[l];
    blocks[l]:=blocks[r];
    blocks[r]:=tmp;
    l:=l+1;
    r:=r-1;
    end;
  end;
if l<rc then qs(l,rc);
if r>lc then qs(lc,r);
end;

begin
readln(n);
for i:=1 to n do
  read(blocks[i]);
qs(1,n);
write(blocks[1]);
for i:=2 to n do
  write(' ',blocks[i]);
end.