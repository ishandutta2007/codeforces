program Policeman;
var n, i, police, sum, tmp: integer;
begin
readln(n);
sum:=0;
police:=0;
for i:=1 to n do
  begin
  read(tmp);
  if (tmp=-1) and (police=0) then sum:=sum+1 else police:=police+tmp;
  end;
writeln(sum);
end.