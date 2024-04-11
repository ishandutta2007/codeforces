program Project2;

{$APPTYPE CONSOLE}

var n: longint;
begin
  read(n);
  randomize;
  if (n = 5) then write(1) else
  write(n mod 3 + 1);
  //readln(n);
end.