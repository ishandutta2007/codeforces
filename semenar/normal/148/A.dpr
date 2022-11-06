program AngryPrincess;
var k, l, m, n, d, sum, i: integer;
begin
  readln(k);
  readln(l);
  readln(m);
  readln(n);
  readln(d);
  sum:=0;
  for i:=1 to d do
    if ((i mod k)=0) or ((i mod l)=0) or ((i mod m)=0) or ((i mod n)=0) then sum:=sum+1;
  writeln(sum);
end.