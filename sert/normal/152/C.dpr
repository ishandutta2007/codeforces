program a108;

{$APPTYPE CONSOLE}

var a: array[1..100, 1..30] of longint;
    kol: array[1..300] of longint;
    s: string;
    i, n, j, k: longint;
    rez: int64;

begin
  //reset(input, 'i.i');
  //rewrite(output, 'o.o');
  readln(n, k);
  for j := 1 to n do
  begin
    readln(s);
    for i := 1 to length(s) do
    begin
      k := ord(s[i]) - ord('A') + 1;
      a[i, k] := 1;
    end;
  end;
  rez := 1;
  for i := 1 to length(s) do
    for j := 1 to 30 do
      kol[i] := kol[i] + a[i, j];
  for i := 1 to length(s) do
    rez := (rez * kol[i]) mod 1000000007;
  write(rez);
end.