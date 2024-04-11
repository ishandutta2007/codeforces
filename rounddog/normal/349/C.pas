
program cf202_3;

var
    i,j,k,m,n:longint;
    l:int64;

begin
  readln(n);
  k:=0;
  l:=0;
  for i:= 1 to n do
    begin
      read(m);
      l:=l+m;
      if m>k then k:=m;
    end;
  readln;
  j:=(l-1) div (n-1)+1;
  if j>k then writeln(j) else writeln(k);
end.