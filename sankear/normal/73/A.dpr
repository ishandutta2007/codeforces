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
  x, y, z, k, l, r, m1, m2, i, j : integer;
  ans, f1, f2 : int64;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(x, y, z, k);
  ans := 0;
  for i := 0 to x - 1 do begin
    if k - i - z + 1 >= 0 then
      ans := max(ans, int64(i + 1) * (min(k - i - z + 1, y - 1) + 1) * z);
    l := k - i - z + 2;
    r := min(k - i, y - 1);
    if l <= r then begin
      while r - l > 2 do begin
        m1 := l + (r - l) div 3;
        f1 := int64(i + 1) * (m1 + 1) * (k - i - m1 + 1);
        m2 := r - (r - l) div 3;
        f2 := int64(i + 1) * (m2 + 1) * (k - i - m2 + 1);
        ans := max(ans, max(f1, f2));
        if f1 < f2 then
          l := m1
        else
          r := m2;
      end;
      for j := l to r do
        ans := max(ans, int64(i + 1) * (j + 1) * (k - i - j + 1));
    end;
  end;
  writeln(ans);
end.