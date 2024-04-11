
program cf225_1;

var
    i,j,k,l,m,n:longint;

begin
  readln(n);
  writeln((n*n+1) div 2);
  for i:= 1 to n do
    begin
      for j:= 1 to n do
        if (i+j) mod 2=0 then write('C') else write('.');
      writeln;
    end;
end.