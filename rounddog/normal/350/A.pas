
program cf203_1;

var
    i,j,k,l,m,n:longint;
    max,min,max2,min2:longint;

begin
  readln(n,m);
  max:=0;
  min:=10000;
  for i:= 1 to n do
    begin
      read(k);
      if k>max then max:=k;
      if k<min then min:=k;
    end;
  readln;
  max2:=0;
  min2:=10000;
  for i:= 1 to m do
    begin
      read(k);
      if k>max2 then max2:=k;
      if k<min2 then min2:=k;
    end;
  readln;
  if min2<=max then writeln(-1)
  else if min2<=2*min then writeln(-1)
  else if max<=2*min then writeln(2*min) else writeln(max);
end.