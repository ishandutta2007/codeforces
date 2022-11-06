program Lineland;
var n, i: integer;
mini, maxi, towns: array [1..100000] of integer;

function min(a,b:integer): integer;
begin
if a>b then min:=b else min:=a;
end;

function max(a,b:integer): integer;
begin
if a<b then max:=b else max:=a;
end;

begin
readln(n);
for i:=1 to n do
  read(towns[i]);
for i:=1 to n do
  maxi[i]:=max(towns[n]-towns[i],towns[i]-towns[1]);
for i:=2 to n-1 do
  mini[i]:=min(towns[i+1]-towns[i],towns[i]-towns[i-1]);
mini[1]:=towns[2]-towns[1];
mini[n]:=towns[n]-towns[n-1];
for i:=1 to n do
  writeln(mini[i],' ',maxi[i]);
end.