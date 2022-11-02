program solution;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Math;

var
  n, m, v, i, f, t : integer;
  a, b, num : array[1..100000] of integer;

begin
  //reset(input, 'input.txt');
  //rewrite(output, 'output.txt');
  read(n, m, v);
  for i := 1 to n do
    num[i] := i;
  if m < 2 then begin
    write(-1);
    halt(0);
  end;
  a[1] := 1;
  b[1] := 2;
  a[2] := 2;
  b[2] := 3;
  if m - 2 < n - 3 then begin
    write(-1);
    halt(0);
  end;
  f := 3;
  t := 4;
  for i := 3 to n - 1 do begin
    a[i] := f;
    b[i] := t;
    inc(f);
    inc(t);
  end;
  f := 2;
  t := 4;
  if (t > n) and (m - n + 1 > 0) then begin
    write(-1);
    halt(0);
  end;
  for i := n to m do begin
    a[i] := f;
    b[i] := t;
    inc(t);
    if t > n then begin
      inc(f);
      t := f + 2;
      if (t > n) and (i < m) then begin
        write(-1);
        halt(0);
      end;
    end;
  end;
  num[2] := v;
  num[v] := 2;
  for i := 1 to m do
    writeln(num[a[i]], ' ', num[b[i]]);
end.