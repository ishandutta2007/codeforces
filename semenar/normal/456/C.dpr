program Lazy;
var n, i, tmp: integer;
a: array [1..100000] of int64;
b: array [0..100000] of int64;

function max(a,b:int64):int64;
begin
if a>b then max:=a else max:=b;
end;

begin
readln(n);
b[0]:=0;
for i:=1 to 100000 do
  a[i]:=0;
for i:=1 to n do
  begin
  read(tmp);
  a[tmp]:=a[tmp]+1;
  end;
b[1]:=a[1];
for i:=2 to 100000 do
  b[i]:=max(b[i-1],b[i-2]+a[i]*i);
writeln(b[100000]);
end.