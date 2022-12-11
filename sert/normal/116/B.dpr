var a, q: array[-1..11, -1..11] of integer;
    b: array[0..11, 0..11] of char;
    u: array[0..11, 0..11] of integer;
    k, n, m, ii, jj, i, j, kol: longint;
begin
//reset(input,'i.i');
//rewrite(output,'o.o');
readln(n, m);
for i := 1 to n do begin for j := 1 to m - 1 do read(b[i, j]); readln(b[i, m]); end;
for i := 1 to n do for j := 1 to m do if b[i, j] = 'W' then u[i, j] := 1;
for i := 1 to n do for j := 1 to m do
if b[i, j] = 'P' then
begin
  k := 0;
  if b[i - 1, j] = 'W' then inc(k);
  if b[i + 1, j] = 'W' then inc(k);
  if b[i, j + 1] = 'W' then inc(k);
  if b[i, j - 1] = 'W' then inc(k);
  if k >= 2 then
  begin
    q[i, j] := 9;
    for ii := 1 to 10 do for jj := 1 to 10 do
    if (b[ii, jj] = 'P') and (q[ii, jj] = 9) then
    begin
      if b[ii - 1, jj] = 'W' then begin q[ii-1,jj-1]:=9;q[ii-2,jj]:=9;q[ii-1,jj+1]:=9;end;
      if b[ii + 1, jj] = 'W' then begin q[ii+1,jj+1]:=9;q[ii+2,jj]:=9;q[ii+1,jj+1]:=9;end;
      if b[ii, jj + 1] = 'W' then begin q[ii+1,jj+1]:=9;q[ii,jj+2]:=9;q[ii-1,jj+1]:=9;end;
      if b[ii, jj - 1] = 'W' then begin q[ii+1,jj-1]:=9;q[ii,jj-2]:=9;q[ii-1,jj-1]:=9;end;
    end;
  end;
end;
  kol := 0;
  for i := 1 to n do for j := 1 to m do
  if b[i,j] = 'P' then
  if (q[i, j] = 9)or(u[i, j+1]=1)or(u[i,j-1]=1)or(u[i+1,j]=1)or(u[i-1,j]=1) then
  begin inc(kol); u[i, j+1]:=2;u[i,j-1]:=2;u[i+1,j]:=2;u[i-1,j]:=2; end;
  write(kol);
end.