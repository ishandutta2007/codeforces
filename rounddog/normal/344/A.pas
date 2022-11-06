
program cf200_1;

var
    i,j,n,s,m:longint;

begin
  readln(n);
  j:=0;
  for i:= 1 to n do
    begin
      readln(m);
      if m<>j then begin
        inc(s);
        j:=m;
      end;
    end;
  writeln(s);
end.