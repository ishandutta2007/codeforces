program Valera;
var cur, pn, i, k, exists: integer;
podkova: array [1..4] of integer;
begin
pn:=0;
for i:=1 to 4 do
  begin
  read(cur);
  exists:=0;
  for k:=1 to pn do
    if cur = podkova[k] then exists:=1;
  if exists=0 then
    begin
    pn:=pn+1;
    podkova[pn]:=cur;
    end;
  end;
writeln(4-pn);
end.