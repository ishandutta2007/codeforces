var s, k: string;
    n, i, l, r: longint;
    fail: boolean;
    a4, a7: longint;

begin
  //reset(input,'i.i');
  //rewrite(output,'o.o');
  readln(s);
  readln(k);
  a4 := 0;
  a7 := 0;
  for i := 1 to length(s) do
    if s[i] <> k[i] then
      if s[i] = '4' then
        inc(a4)
      else
        inc(a7);
  if a7 > a4 then
    write(a7)
  else
    write(a4);
end.