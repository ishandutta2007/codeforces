const md=1000000009;
var n,i:longint;
    d2,d:int64;
begin
  read(n);
  n:=n div 2;
  d:=1;
  for i:=3 to n do d:=(d*2+3)mod md;
  d2:=1;
  for i:=n-1 downto 1 do begin
    d2:=(1+d*(3+d2))mod md;
    d:=((d-3)*((md+1)div 2))mod md;
  end;
  writeln((4*d2+4+2*d2*d2)mod md);
end.