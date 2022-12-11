program Project2;

{$APPTYPE CONSOLE}

var n: longint;
    ans, i: longint;
begin
  read(n);
  ans := 1;
  for i := 1 to n - 1 do
    ans := ans + 12 * i;
  write(ans);
  readln(n);
end.