program solution;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  n, k, kp, i, j, ans : integer;
  fl : boolean;
  p : array[1..1000] of integer;
  prime, used : array[1..1000] of boolean;

begin
  //reset(input, 'input.txt');
  //rewrite(output, 'output.txt');
  read(n, k);
  kp := 0;
  for i := 2 to n do begin
    fl := true;
    j := 2;
    while j * j <= i do begin
      if i mod j = 0 then begin
        fl := false;
        break;
      end;
      inc(j);
    end;
    if fl then begin
      inc(kp);
      prime[i] := true;
      p[kp] := i;
    end;
  end;
  for i := 1 to kp - 1 do
    if p[i] + p[i + 1] + 1 <= n then
      used[p[i] + p[i + 1] + 1] := true;
  ans := 0;
  for i := 1 to n do
    if (used[i]) and (prime[i]) then
      inc(ans);
  if ans >= k then
    write('YES')
  else
    write('NO');
end.