program solution;

{$APPTYPE CONSOLE}
{MODE DELPHI}
{$MAXSTACKSIZE 1000000000}
{O-,R+,Q+}
{$O+,R-,Q-}

uses
  SysUtils,
  Math;

const
  inf = round(1e9);

var
  n, m, k, ka, i, j, kol, ans : integer;
  a, d, x : array[0..101] of integer;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n, m, k);
  for i := 1 to m do
    read(d[i]);
  for i := 1 to k do
    read(x[i]);
  ans := inf;
  ka := 0;
  for i := 1 to m do begin
    kol := 0;
    for j := 1 to k do
      if x[j] = n + 1 then
        inc(kol)
      else
        if (x[j] <= n) and (x[j] mod d[i] = 0) then
          inc(kol);
    if kol < ans then begin
      ans := kol;
      ka := 1;
      a[1] := i;
    end
    else
      if kol = ans then begin
        inc(ka);
        a[ka] := i;
      end;
  end;
  writeln(ka);
  for i := 1 to ka do
    write(a[i], ' ');
  writeln;
end.