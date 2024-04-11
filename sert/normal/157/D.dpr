program a110;

{$APPTYPE CONSOLE}

var a, b: array[1..100000] of longint;
    rev, rez, first, next, last: array[1..100000] of longint;
    s, k: string;
    ch: char;
    code: integer;
    du, find, kol, i, j, n, p, t, l, m: longint;
    only: boolean;

begin
  //reset(input,'i.i');
  //rewrite(output,'o.o');
  kol := 0;
  find := 0;
  only := true;
  readln(n, m);
  for i := 1 to n do
  begin
    readln(s);
    ch := s[1];
    delete(s, 1, 1);
    val(s, p, code);
    if ch = '+' then inc(a[p]) else begin inc(b[p]); inc(kol); rev[i] := -1; end;
    if first[p] = 0 then first[p] := i else next[last[p]] := i;
    last[p] := i;
  end;
  for i := 1 to n do b[i] := kol - b[i];
  for i := 1 to n do
    if a[i] + b[i] = m then
    begin
      if find = 1 then only := false;
      if find = 0 then inc(find);
      du := first[i];
      while du <> 0 do
      begin
        rez[du] := 7;
        du := next[du];
      end;
    end;
  for i := 1 to n do
    if rez[i] = 0 then
      if rev[i] = -1 then
        writeln('Truth')
      else
        writeln('Lie') else
    if only then
      if rev[i] = -1 then
        writeln('Lie')
      else
        writeln('Truth')
    else
      writeln('Not defined');
end.