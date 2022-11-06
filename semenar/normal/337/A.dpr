program Puzzles;
var n, m, i, min_puzzle: integer;
puzzle: array [1..100] of integer;

procedure qs(lc,rc:integer);
var l, r, x, tmp: integer;
begin
l:=lc;
r:=rc;
x:=puzzle[lc+((rc-lc) div 2)];
while l<=r do
  begin
  while puzzle[l]<x do l:=l+1;
  while puzzle[r]>x do r:=r-1;
  if l<=r then
    begin
    tmp := puzzle[l];
    puzzle[l] := puzzle[r];
    puzzle[r] := tmp;
    l:=l+1;
    r:=r-1;
    end;
  end;
if (l<rc) then qs(l,rc);
if (r>lc) then qs(lc,r);
end;

begin
readln(n, m);
for i:=1 to m do
  read(puzzle[i]);
qs(1,m);
min_puzzle:=puzzle[n]-puzzle[1];
for i:=2 to m-n+1 do
  if (puzzle[i+n-1]-puzzle[i]) < min_puzzle then min_puzzle:=puzzle[i+n-1]-puzzle[i];
writeln(min_puzzle);
end.