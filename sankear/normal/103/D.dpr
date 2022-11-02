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
  sz = 600;

var
  n, m, a, b, k, i, j : integer;
  w, q, num, next : array[0..300001] of integer;
  ans, sol : array[0..300001] of int64;
  first : array[0..1301] of integer;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  //writeln((sizeof(w) + sizeof(q) + sizeof(num) + sizeof(next) + sizeof(ans) + sizeof(sol) + sizeof(first)) div 1024 div 1024);
  read(n);
  for i := 1 to n do
    read(w[i]);
  read(m);
  k := 0;
  for i := 1 to m do begin
    read(a, b);
    if ((n - a) div b) + 1 <= sz then begin
      j := a;
      while j <= n do begin
        sol[i] := sol[i] + w[j];
        j := j + b;
      end;
      continue;
    end;
    inc(k);
    q[k] := a;
    num[k] := i;
    next[k] := first[b];
    first[b] := k;
  end;
  for i := 1 to sz do begin
    for j := 1 to n do
      ans[j] := w[j];
    for j := n downto 1 do
      if j + i <= n then
        ans[j] := ans[j] + ans[j + i];
    j := first[i];
    while j > 0 do begin
      sol[num[j]] := ans[q[j]];
      j := next[j];
    end;
  end;
  for i := 1 to m do
    writeln(sol[i]);
end.