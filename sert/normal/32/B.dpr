program aeq;

{$APPTYPE CONSOLE}

var s: string; i, n, k, l, j: longint;
begin
//reset(input,'i.i');
//rewrite(output,'o.o');
  read(s);
  i := 1;
  while i < length(s) do
  begin
    while (s[i] <> '-')and(i <= length(s)) do begin inc(i); write('0'); end;
    k := 0;
    while (s[i] <> '.')and(i <= length(s)) do begin
    inc(k); inc(i); end;
    for j := 1 to k div 2 do begin
    write('2'); end;
    if k mod 2 = 1 then begin
    write('1'); inc(i); end;
  end;
  if i = length(s) then
  write('0');
  readln(k);
end.