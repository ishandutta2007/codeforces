program WUBWUB;
var i, slovo: integer;
dubstep, classic: string;
begin
readln(dubstep);
classic:='';
i:=1;
slovo:=0;
while i <= length(dubstep) do
  begin
  if i <= length(dubstep)-2 then
    if (dubstep[i]='W') and (dubstep[i+1]='U') and (dubstep[i+2]='B') then
      begin;
      if slovo=1 then slovo:=2;
      i:=i+3;
      continue;
      end;
  if (slovo=2) then
    classic:=classic+' ';
  slovo:=1;
  classic:=classic+dubstep[i];
  i:=i+1;
  end;
writeln(classic);
end.