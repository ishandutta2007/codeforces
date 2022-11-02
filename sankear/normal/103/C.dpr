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
  m, i : integer;
  n, k, g : int64;
  x : array[0..1001] of int64;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n, k, m);
  for i := 1 to m do
    read(x[i]);
  if k = 0 then begin
    for i := 1 to m do
      write('.');
    writeln;
    halt;
  end;
  if k = n then begin
    for i := 1 to m do
      write('X');
    writeln;
    halt;
  end;
  if n mod 2 = 0 then begin
    if k <= n div 2 then begin
      for i := 1 to m do
        if (x[i] mod 2 = 0) and ((n div 2) - (x[i] div 2) + 1 <= k) then
          write('X')
        else
          write('.');
      writeln;
      halt;
    end;
    k := k - n div 2;
    g := n - k * 2;
    for i := 1 to m do
      if x[i] >= g then
        write('X')
      else
        if x[i] mod 2 = 0 then
          write('X')
        else
          write('.');
    writeln;
    halt;
  end;
  k := k - 1;
  n := n - 1;
  if k <= n div 2 then begin
    for i := 1 to m do
      if (x[i] = n + 1) or ((x[i] mod 2 = 0) and ((n div 2) - (x[i] div 2) + 1 <= k)) then
        write('X')
      else
        write('.');
    writeln;
    halt;
  end;
  k := k - n div 2;
  g := n - 2 * k;
  for i := 1 to m do
    if x[i] >= g then
      write('X')
    else
      if x[i] mod 2 = 0 then
        write('X')
      else
        write('.');
  writeln;
end.