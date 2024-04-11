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
  n, k, l, r, i : integer;
  s : string;
  used : array[0..27] of boolean;
  a : array[0..101] of integer;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  readln(k);
  readln(s);
  n := length(s);
  for i := 1 to n do
    if s[i] = '?' then
      a[i] := 0
    else
      a[i] := ord(s[i]) - ord('a') + 1;
  for i := 1 to n do
    if a[i] > 0 then
      used[a[i]] := true;
  if n mod 2 = 0 then begin
    l := n div 2;
    r := n div 2 + 1;
  end
  else begin
    l := (n + 1) div 2;
    r := (n + 1) div 2;
  end;
  while (l > 0) and (r <= n) do begin
    if a[l] > 0 then begin
      if a[r] = 0 then
        a[r] := a[l]
      else
        if a[r] <> a[l] then begin
          writeln('IMPOSSIBLE');
          halt(0);
        end;
    end
    else
      if a[r] > 0 then begin
        if a[l] = 0 then
          a[l] := a[r]
        else
          if a[l] <> a[r] then begin
            writeln('IMPOSSIBLE');
            halt(0);
          end;
      end
      else begin
        for i := k downto 1 do
          if not used[i] then begin
            a[l] := i;
            a[r] := i;
            used[i] := true;
            break;
          end;
        if (a[l] = 0) or (a[r] = 0) then begin
          a[l] := 1;
          a[r] := 1;
        end;
      end;
    dec(l);
    inc(r);
  end;
  for i := 1 to k do
    if not used[i] then begin
      writeln('IMPOSSIBLE');
      halt(0);
    end;
  for i := 1 to n do
    write(chr(ord('a') + a[i] - 1));
  writeln;
end.