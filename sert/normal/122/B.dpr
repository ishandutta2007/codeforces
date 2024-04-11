program C91;

{$APPTYPE CONSOLE}

Var n, i: longint;
    s: string;
    a4, a7: longint;
begin
  //reset(input,'i.i');
  //rewrite(output,'o.o');
  read(s);
  a4 := 0;
  a7 := 0;
  for i := 1 to length(s) do
    if s[i] = '4' then inc(a4) else if s[i] = '7' then inc(a7);

  if a4 + a7 = 0 then
    write(-1) else
  if a4 >= a7 then write(4) else write(7);

end.