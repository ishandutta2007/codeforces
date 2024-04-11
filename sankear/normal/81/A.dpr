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
  n, k, aa, bb, i : integer;
  s : string;
  del : array[0..1000001] of boolean;
  prev, next, a, b : array[0..1000001] of integer;

procedure doit(a : integer);
begin
  del[a] := true;
  next[prev[a]] := next[a];
  if next[a] > 0 then
    prev[next[a]] := prev[a];
end;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  readln(s);
  n := length(s);
  next[0] := 1;
  for i := 1 to n do begin
    prev[i] := i - 1;
    next[i] := i + 1;
  end;
  next[n] := 0;
  k := 0;
  for i := 1 to n - 1 do
    if s[i] = s[i + 1] then begin
      inc(k);
      a[k] := i;
      b[k] := i + 1;
    end;
  while k > 0 do begin
    if (not del[a[k]]) and (not del[b[k]]) then begin
      aa := prev[a[k]];
      bb := next[b[k]];
      doit(a[k]);
      doit(b[k]);
      dec(k);
      if (aa > 0) and (bb > 0) and (s[aa] = s[bb]) then begin
        inc(k);
        a[k] := aa;
        b[k] := bb;
      end;
      continue;
    end;
    dec(k);
  end;
  i := 0;
  while next[i] > 0 do begin
    i := next[i];
    write(s[i]);
  end;
  writeln;
end.