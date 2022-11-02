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
  n, sum, cur, ans, i : integer;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n);
  ans := 0;
  sum := 0;
  cur := 5;
  for i := 1 to 100 do begin
    sum := sum + cur;
    if sum >= n then
      break;
    ans := i;
    cur := cur * 2;
  end;
  sum := 0;
  cur := 5;
  for i := 1 to ans do begin
    sum := sum + cur;
    cur := cur * 2;
  end;
  ans := 1 shl ans;
  n := n - sum;
  if n mod ans = 0 then
    ans := n div ans
  else
    ans := n div ans + 1;
  if ans = 1 then begin
    writeln('Sheldon');
    halt;
  end;
  if ans = 2 then begin
    writeln('Leonard');
    halt;
  end;
  if ans = 3 then begin
    writeln('Penny');
    halt;
  end;
  if ans = 4 then begin
    writeln('Rajesh');
    halt;
  end;
  writeln('Howard');
end.