program Dvoika;
var x, sum, st: integer;
begin
  st := 1073741824;
  sum := 0;
  readln(x);
  while (st > 0) do
    begin
    if (x >= st) then
      begin
      x := x-st;
      sum := sum+1;
      end;
    st := st div 2;
    end;
   writeln(sum);
end.