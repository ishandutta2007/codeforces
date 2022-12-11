var q, h, n, m, k, i, j, sw, ma: longint;
    a: array[1..101,1..101] of longint;
begin
read(n, m);
if n*m = 1 then begin write(1); halt; end;
if ((n=2)and(m=2))or(n*m<=3)then write(-1) else
begin
if ((n=3)and(m=2)) then begin
writeln('3 5');
writeln('6 1');
writeln('2 4'); end;
if (n=2)and(m=3) then begin
writeln('3 6 2'); writeln ('5 1 4'); end;
if (n = 3)and(m=3) then
begin
writeln('3 7 2');
writeln('5 1 4');
writeln('8 6 9'); end;
if (m>3)or(n>3) then begin
if m < 4 then begin
sw := m; m := n; n := sw; sw := 1; end;
for i := 1 to n do
begin

  h := m*(i-1)+1;
  if m = 4 then inc(h);
  ma := h+m;
  a[i,1] := h;
  q:=1;
  while h+2<ma do begin inc(q); h := h+2; a[i,q] := h;end;
  h := m*(i-1)+2;
  if m = 4 then dec(h);
  a[i,q+1] := h;
  inc(q);
  while h+2<ma do begin inc(q); h := h+2; a[i,q] := h;end;
end;

if sw = 0 then
for i := 1 to n do begin for j := 1 to m do
write(a[i, j],' '); writeln; end else
for i := 1 to m do begin for j := 1 to n do
write(a[j, i],' '); writeln; end
end;
end;
end.