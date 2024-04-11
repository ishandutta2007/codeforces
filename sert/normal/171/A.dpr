program Project2;

{$APPTYPE CONSOLE}

var n, a, b: longint;
    ans, i: longint;
begin
  read(a, b);
  n := 0;
  while b > 0 do
  begin
    n := n * 10 + b mod 10;
    b := b div 10;
  end;
  write(a + n);
  //readln(a);
end.