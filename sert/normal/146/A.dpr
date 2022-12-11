var s: string;
    n, i, l, r: longint;
    fail: boolean;

begin
  //reset(input,'i.i');
  //rewrite(output,'o.o');
  readln(n);
  read(s);
  fail:= false;
  l := 0;
  r := 0;
  for i := 1 to length(s) do
  begin
    if i <= length(s) div 2 then
      l := l + ord(s[i]) - ord('0')
    else
      r := r + ord(s[i]) - ord('0');
    if (s[i] <> '4') and (s[i] <> '7') then
      fail := true;
  end;

  if (l = r) and (not fail) then
    writeln('YES')
  else
    writeln('NO');

  //writeln(fail);
  //writeln(l, ' ', r);
  
end.