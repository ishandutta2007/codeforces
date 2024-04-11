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
  n, i, j, add : integer;
  val : int64;
  used, sum, f : array[0..100001] of integer;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n);
  for i := 3 to n do begin
    for j := 2 to i do begin
      val := i - (int64(j) * (j - 1)) div 2;
      if val <= 0 then
        break;
      if val mod j <> 0 then
        continue;
      val := val div j;
      add := sum[val + j - 1] xor sum[val - 1];
      used[add] := i;
    end;
    for j := 0 to n do
      if used[j] <> i then begin
        f[i] := j;
        break;
      end;
    sum[i] := sum[i - 1] xor f[i];
  end;
  if f[n] = 0 then begin
    writeln(-1);
    halt;
  end;
  for i := 2 to n do begin
    val := n - (int64(i) * (i - 1)) div 2;
    if val mod i <> 0 then
      continue;
    val := val div i;
    add := sum[val + i - 1] xor sum[val - 1];
    if add = 0 then begin
      writeln(i);
      halt;
    end;
  end;
end.