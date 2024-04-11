program Portals;
var n, t, i, cur, tmp: integer;
ans: string;
begin
readln(n,t);
ans:='NO';
cur:=1;
for i:=1 to n-1 do
  begin
  read(tmp);
  if (i=cur) then cur:=cur+tmp;
  if (t=cur) then ans:='YES';
  end;
writeln(ans);
end.