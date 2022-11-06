program EpicFail;
var a, b, n, cur, cur_nod: integer;

function nod(a, b: integer): integer;
begin
if (a=0) or (b=0) then nod:=a+b
else if (a<b) then nod:=nod(a,b mod a) else nod:=nod(a mod b,b);
end;

begin
readln(a,b,n);
cur:=1;
while true do
  begin
  if cur=1 then cur_nod:=nod(a,n) else cur_nod:=nod(b,n);
  if n<cur_nod then break;
  n:=n-cur_nod;
  cur:=1-cur;
  end;
writeln(cur);
end.