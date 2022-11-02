program codeforces;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  n, m, a, h, w : int64;

begin
  //reset(input, 'input.txt');
  //rewrite(output, 'output.txt');
  read(n, m, a);
  w := m div a;
  if m mod a > 0 then
    inc(w);
  h := n div a;
  if n mod a > 0 then
    inc(h);
  write(h * w);
end.