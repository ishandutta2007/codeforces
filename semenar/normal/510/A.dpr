program Zmeika;
var i, n, m: integer;
zm: array [1..50] of string;
begin
readln(n,m);
zm[1]:='';
for i:=1 to m do
  zm[1]:=zm[1]+'#';
for i:=1 to (n div 2) do
  zm[2*i+1]:=zm[1];
zm[2]:='';
for i:=1 to m do
  zm[2]:=zm[2]+'.';
for i:=1 to (n div 2) - 1 do
  zm[2*i+2]:=zm[2];
for i:=1 to (n div 4) do
  begin
  zm[4*i][1]:='#';
  zm[4*i-2][m]:='#';
  end;
if (n mod 4) = 3 then zm[n-1][m]:='#';
for i:=1 to n do
  writeln(zm[i]);
end.