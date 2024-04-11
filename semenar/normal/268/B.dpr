program CodeBlock;
var n, i: integer;
pressings, errors: array [1..2000] of int64;
begin
readln(n);
pressings[1]:=1;
errors[1]:=0;
for i:=2 to n do
  begin
  pressings[i]:=i+pressings[i-1]+errors[i-1];
  errors[i]:=i-1+errors[i-1];
  end;
writeln(pressings[n]);
end.