program Slon;
var i, kv: integer;
sticks: array [1..9] of integer;
begin
for i:=1 to 9 do
  sticks[i]:=0;
for i:=1 to 6 do
  begin
  read(kv);
  sticks[kv]:=sticks[kv]+1;
  end;
kv:=0;
for i:=1 to 9 do
  kv:=kv+sticks[i]*sticks[i]*sticks[i];
if (kv=66) or (kv=126) then writeln('Bear') else if (kv=72) or (kv=216) then writeln('Elephant') else writeln('Alien');
end.