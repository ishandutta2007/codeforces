program IQ;
var n, n0, n1, num0, num1, i, tmp: integer;
begin
readln(n);
n0:=0;
n1:=0;
for i:=1 to n do
  begin
  read(tmp);
  if (tmp mod 2)=0 then 
    begin
    n0:=n0+1;
    num0:=i;
    end
  else
    begin
    n1:=n1+1;
    num1:=i;
    end;
  end;
if n0>1 then writeln(num1) else writeln(num0);
end.