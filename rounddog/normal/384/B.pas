
program cf225_2;

var
    i,j,k,l,m,n,p:longint;

begin
  readln(n,m,p);
  for i:= 1 to n do
    for j:= 1 to m do
      read(k);
  readln;
  writeln(m*(m-1) div 2);
  for i:= m downto 2 do
    for j:= 1 to i-1 do
      if p=0 then writeln(j,' ',j+1) else writeln(j+1,' ',j);

end.