program solution;

{$APPTYPE CONSOLE}
{$MAXSTACKSIZE 100000000}
{$O+,R-,Q-}

uses
  SysUtils,
  Math;

var
  n, i, j, k : integer;
  s : string;
  t : array[0..101] of string;
  a : array[0..101] of integer;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  readln(n);
  for i := 1 to n do
    readln(t[i]);
  for i := 1 to n - 1 do
    for j := n downto i + 1 do
      if t[i] > t[j] then begin
        s := t[i];
	t[i] := t[j];
	t[j] := s;
      end;
  k := 1;
  a[1] := 1;
  for i := 2 to n do
    if t[i] > t[i - 1] then begin
      inc(k);
      a[k] := 1;
    end
    else
      inc(a[k]);
  if k = 1 then
    write(t[1])
  else 
    if a[1] > a[2] then
      write(t[1])
    else
      write(t[n]);
end.