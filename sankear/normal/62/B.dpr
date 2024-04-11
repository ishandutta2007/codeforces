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
  n, k, p, len, l, r, mid, res, i, j : integer;
  ans : int64;
  c : char;
  s : string;
  kol : array['a'..'z'] of integer;
  a : array['a'..'z', 0..200001] of integer;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  readln(n, k);
  readln(s);
  for i := 1 to k do begin
    c := s[i];
    inc(kol[c]);
    a[c, kol[c]] := i;
  end;
  for i := 1 to n do begin
    readln(s);
    len := length(s);
    ans := 0;
    for j := 1 to len do begin
      c := s[j];
      if kol[c] = 0 then begin
        ans := ans + len;
        continue;
      end;
      res := inf;
      l := 1;
      r := kol[c];
      while l <= r do begin
        mid := l + (r - l) div 2;
        p := a[c, mid];
        if p <= j then begin
          res := min(res, j - p);
          l := mid + 1;
        end
        else
          r := mid - 1;
      end;
      l := 1;
      r := kol[c];
      while l <= r do begin
        mid := l + (r - l) div 2;
        p := a[c, mid];
        if p > j then begin
          res := min(res, p - j);
          r := mid - 1;
        end
        else
          l := mid + 1;
      end;
      ans := ans + res;
    end;
    writeln(ans);
  end;
end.