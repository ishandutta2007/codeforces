
var n, m, k, i, j: longint;
    o: array[0..2] of longint;
    s, t, y, fail: longint;
begin

read(n, m);
fail := n; n := m; m := fail;
if (n = 1) and (m = 2) then
begin
writeln(0);
writeln('1 1');
writeln('2 1');
writeln('1 1');
halt;
end;
if (n = 2) and (m = 1) then
begin
  writeln(0);
writeln('1 1');
writeln('1 2');
writeln('1 1');
halt;
end;

if n = 1 then begin
   writeln(1);
   writeln(m, ' ', 1, ' ', 1, ' ', 1);
   for i := 1 to m do writeln(i, ' ', 1);
   writeln('1 1');

  halt;
end;
if m = 1 then begin
   writeln(1);
   writeln(1, ' ', n, ' ', 1, ' ', 1);
   for i := 1 to n do writeln(1, ' ', i);
   writeln('1 1');

  halt;
end;

if (n*m)mod 2 = 1 then begin writeln(1); writeln(m, ' ', n, ' ', m, ' ', 1); end
else writeln(0);
if n mod 2 = 0 then begin
  writeln('1 1');
  for j := 1 to n div 2 do
  begin
  for i := 2 to m do writeln(i, ' ', j*2-1);
  for i := m downto 2 do writeln(i, ' ', j*2);
  end;
  for i := n downto 1 do writeln(1, ' ', i);
  halt;
end;
if m mod 2 = 0 then begin
  writeln('1 1');
  for j := 1 to m div 2 do
  begin
  for i := 2 to n do writeln(j*2-1, ' ', i);
  for i := n downto 2 do writeln(j*2, ' ', i);
  end;
  for i := m downto 1 do writeln(i, ' ', 1);

halt;
end;

writeln('1 1');
  for j := 1 to m div 2 do
  begin
  for i := 2 to n do writeln(j*2-1, ' ', i);
  for i := n downto 2 do writeln(j*2, ' ', i);
  end;
  for i := 2 to n do writeln(m, ' ', i);
  for i := m downto 1 do writeln(i, ' ', 1);

end.