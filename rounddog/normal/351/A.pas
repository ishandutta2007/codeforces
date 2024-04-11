
program cf204_1;

var
    i,j,k,l,m,n:longint;
    r,sum:real;

function min(x,y:real):real;
begin
  if x<y then min:=x else min:=y;
end;

begin
  k:=0;
  sum:=0;
  readln(n);
  for i:= 1 to 2*n do
    begin
      read(r);
      sum:=sum+r-trunc(r);
      if r=trunc(r) then inc(k);
    end;
  if sum-n>0 then writeln(sum-n:0:3) else begin
    sum:=abs(sum-n);
    if sum>k then writeln(sum-k:0:3) else
    writeln(min(sum-trunc(sum),trunc(sum+1)-sum):0:3);
  end;
end.