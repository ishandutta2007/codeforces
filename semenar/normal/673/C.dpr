program Round3div2;
var colours, ans, curcolours: array [1..5000] of integer;
n, i, k, curans: integer;

begin
  readln(n);
  for i:=1 to n do
    read(colours[i]);
  for i:=1 to n do
    ans[i] := 0;
  for i:=1 to n do
    begin
    for k:=1 to n do curcolours[k]:=0;
    curans:=n;
    for k:=i to n do
      begin
      curcolours[colours[k]]:=curcolours[colours[k]]+1;
      if (curcolours[colours[k]] > curcolours[curans]) or ((curcolours[colours[k]] = curcolours[curans]) and (colours[k] < curans)) then curans:=colours[k];
      ans[curans]:=ans[curans]+1;
      end;
    end;
  for i:=1 to n do
    write(ans[i],' ');
end.