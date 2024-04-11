program dinamka;

{$APPTYPE CONSOLE}

var s1, s: array[1..100] of string [105];
    n, k, i, j, u: longint;
    st, iz: string;
begin

readln(n);
for i := 1 to n do
begin
  readln(st);
  if length(st) <= 10 then writeln(st) else begin
  write(st[1]);
  write(length(st)-2);
  writeln(st[length(st)]);end;
end;

end.