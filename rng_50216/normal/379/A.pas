
var c, a, b, ans : longint;


begin
  read(a, b);
  ans := 0;
  c := 0;
  while (a > 0) do begin
    ans += a;
    c := a + c;
    a := c div b;
    c := c mod b;
  end;
  writeln(ans);
end.