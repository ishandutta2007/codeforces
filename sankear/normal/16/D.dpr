program solution;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Math;

const
  maxn = 100;

var
  n, k, i, j, d, p, tp, l : integer;
  s : string;
  h, m : array[1..maxn] of integer;

function ok(a, b : integer) : boolean;
begin
  result := (h[a] < h[b]) or ((h[a] = h[b]) and (m[a] < m[b]));
end;

begin
  //reset(input, 'input.txt');
  //rewrite(output, 'output.txt');
  readln(n);
  for i := 1 to n do begin
    readln(s);
    k := 0;
    tp := 0;
    h[i] := 0;
    m[i] := 0;
    for j := 1 to length(s) do
      if s[j] = ':' then
        inc(k)
      else
        if s[j] = '.' then begin
          if tp = 0 then begin
            if s[j - 1] = 'p' then
              tp := 2
            else
              tp := 1;
          end;
        end
        else
          if s[j] in ['0'..'9'] then begin
            if k = 0 then
              h[i] := h[i] * 10 + ord(s[j]) - ord('0');
            if k = 1 then
              m[i] := m[i] * 10 + ord(s[j]) - ord('0');
          end;
      if (tp = 1) and (h[i] = 12) then
        h[i] := 0;
      if (tp = 2) and (h[i] < 12) then
        h[i] := h[i] + 12;
  end;
  d := 1;
  l := 1;
  for i := 2 to n do begin
    if ok(i, i - 1) then
      inc(d);
    if (h[i] = h[i - 1]) and (m[i] = m[i - 1]) then
      inc(l)
    else
      l := 1;
    if l > 10 then begin
      inc(d);
      l := 1;
    end;
  end;
  write(d);
end.