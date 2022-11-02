program solution;

{$APPTYPE CONSOLE}
{MODE DELPHI}
{$MAXSTACKSIZE 1000000000}
{O-,R+,Q+}
{$O+,R-,Q-}

uses
  SysUtils,
  Math;

var
  a, b, c, d, n, i, j, cur, k : integer;
  x : array[0..101] of integer;
  col : array[0..101, 0..101] of integer;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(a, b, c, d, n);
  for i := 1 to n do
    read(x[i]);
  if (a + 1) mod 2 = 0 then begin
    cur := 1;
    i := b;
    j := 1;
    for k := 1 to a * b + c * d do begin
      col[i, j] := cur;
      dec(x[cur]);
      if x[cur] = 0 then
        inc(cur);
      if j mod 2 = 0 then begin
        inc(i);
        if j <= a then begin
          if i > b then begin
            inc(j);
            i := b;
          end;
        end
        else begin
          if i > d then begin
            inc(j);
            i := d;
          end;
        end;
      end
      else begin
        dec(i);
        if i < 1 then begin
          inc(j);
          i := 1;
        end;
      end;
    end;
  end
  else begin
    cur := 1;
    i := 1;
    j := 1;
    for k := 1 to a * b + c * d do begin
      col[i, j] := cur;
      dec(x[cur]);
      if x[cur] = 0 then
        inc(cur);
      if j mod 2 = 0 then begin
        dec(i);
        if i < 1 then begin
          inc(j);
          i := 1;
        end;
      end
      else begin
        inc(i);
        if j <= a then begin
          if i > b then begin
            inc(j);
            i := b;
          end;
        end
        else begin
          if i > d then begin
            inc(j);
            i := d;
          end;
        end;
      end;
    end;
  end;
  writeln('YES');
  for i := 1 to max(b, d) do begin
    for j := 1 to a + c do
      if col[i, j] = 0 then
        write('.')
      else
        write(chr(ord('a') + col[i, j] - 1));
    writeln;
  end;
end.