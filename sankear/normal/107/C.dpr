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
  n, m, a, b, all, i, ch, j, z : integer;
  y : int64;
  fl : boolean;
  need, ans : array[0..17] of integer;
  sz : array[0..66001] of integer;
  d : array[0..66001] of int64;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n, y, m);
  y := y - 2000;
  for i := 1 to m do begin
    read(a, b);
    need[b] := need[b] or (1 shl (a - 1));
  end;
  all := (1 shl n) - 1;
  for i := 0 to all do
    for j := 1 to n do
      if (i and (1 shl (j - 1))) > 0 then
        inc(sz[i]);
  for i := 1 to n do begin
    fl := false;
    for ch := 1 to n do begin
      ans[i] := ch;
      for j := 0 to all do
        d[j] := 0;
      d[0] := 1;
      for j := 1 to all do
        for z := 1 to n do
          if ((j and (1 shl (z - 1))) > 0) and ((j and need[z]) = 0) and ((ans[z] = 0) or (ans[z] = n - sz[j] + 1)) then
            d[j] := d[j] + d[j xor (1 shl (z - 1))];
      if d[all] >= y then begin
        fl := true;
        break;
      end;
      y := y - d[all];
    end;
    if not fl then begin
      writeln('The times have changed');
      halt;
    end;
  end;
  write(ans[1]);
  for i := 2 to n do
    write(' ', ans[i]);
  writeln;
end.