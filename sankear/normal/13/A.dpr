program codeforces;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  n, i, j, g, ans : integer;

function gcd(a, b : integer) : integer;
begin
  if b = 0 then
    result := a
  else
    result := gcd(b, a mod b);
end;

begin
  //reset(input, 'input.txt');
  //rewrite(output, 'output.txt');
  read(n);
  ans := 0;
  for i := 2 to n - 1 do begin
    j := n;
    while j > 0 do begin
      ans := ans + j mod i;
      j := j div i;
    end;
  end;
  g := gcd(n - 2, ans);
  write(ans div g, '/', (n - 2) div g);
end.