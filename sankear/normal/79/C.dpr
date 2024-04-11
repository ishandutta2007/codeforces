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
  n, len, ans, pos, res, l, r, mid, i, j : integer;
  fl : boolean;
  s : string;
  a : array[0..11] of string;
  b, k, cur : array[0..11] of integer;
  ll, rr : array[0..11, 0..100001] of integer;

function good(c, d : integer) : boolean;
var i : integer;
begin
  result := true;
  for i := c to c + b[d] - 1 do
    if s[i] <> a[d, i - c + 1] then begin
      result := false;
      exit;
    end;
end;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  readln(s);
  readln(n);
  for i := 1 to n do
    readln(a[i]);
  len := length(s);
  for i := 1 to n do
    b[i] := length(a[i]);
  for i := 1 to n do
    for j := 1 to len - b[i] + 1 do
      if good(j, i) then begin
        inc(k[i]);
        ll[i, k[i]] := j;
        rr[i, k[i]] := j + b[i] - 1;
      end;
  for i := 1 to n do
    cur[i] := 1;
  ans := 0;
  pos := 0;
  for i := 1 to len do begin
    for j := 1 to n do begin
      while (cur[j] <= k[j]) and (i > ll[j, cur[j]]) do
        inc(cur[j]);
    end;
    res := 0;
    l := 1;
    r := len - i + 1;
    while l <= r do begin
      mid := (l + r) div 2;
      fl := true;
      for j := 1 to n do
        if (cur[j] <= k[j]) and (rr[j, cur[j]] <= i + mid - 1) then begin
          fl := false;
          break;
        end;
      if fl then begin
        res := mid;
        l := mid + 1;
      end
      else
        r := mid - 1;
    end;
    if res > ans then begin
      ans := res;
      pos := i - 1;
    end;
  end;
  writeln(ans, ' ', pos);
end.