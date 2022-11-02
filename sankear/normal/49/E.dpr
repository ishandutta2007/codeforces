program solution;

{$APPTYPE CONSOLE}
{$MAXSTACKSIZE 1000000000}
{$O+,R-,Q-}

uses
  SysUtils,
  Math;

const
  inf = round(1e9);

var
  n, m, ans, i : integer;
  rs : string;
  s : array[0..3] of string;
  first : array['a'..'z'] of integer;
  go1, go2 : array[0..51] of char;
  next : array[0..51] of integer;
  usef, f : array[0..3, 'a'..'z', 0..51, 0..51] of boolean;
  used : array[0..51, 0..51] of boolean;
  d : array[0..51, 0..51] of integer;

procedure add(c, c1, c2 : char);
begin
  inc(m);
  go1[m] := c1;
  go2[m] := c2;
  next[m] := first[c];
  first[c] := m;
end;

function can(num : integer; c : char; l, r : integer) : boolean;
var i, j : integer;
begin
  if usef[num, c, l, r] then begin
    result := f[num, c, l, r];
    exit;
  end;
  usef[num, c, l, r] := true;
  f[num, c, l, r] := false;
  if l > r then begin
    result := false;
    exit;
  end;
  if (l = r) and (s[num, l] = c) then begin
    f[num, c, l, r] := true;
    result := true;
    exit;
  end;
  j := first[c];
  while j > 0 do begin
    for i := l to r - 1 do begin
      f[num, c, l, r] := can(num, go1[j], l, i) and can(num, go2[j], i + 1, r);
      if f[num, c, l, r] then begin
        result := true;
        exit;
      end;
    end;
    j := next[j];
  end;
  result := f[num, c, l, r];
end;

function calc(n, m : integer) : integer;
var i, j : integer;
z : char;
begin
  if used[n, m] then begin
    result := d[n, m];
    exit;
  end;
  used[n, m] := true;
  d[n, m] := inf;
  if (n = 0) and (m = 0) then begin
    d[n, m] := 0;
    result := 0;
    exit;
  end;
  for i := 1 to n do
    for j := 1 to m do
      for z := 'a' to 'z' do
        if (can(1, z, n - i + 1, n)) and (can(2, z, m - j + 1, m)) then
          d[n, m] := min(d[n, m], calc(n - i, m - j) + 1);
  result := d[n, m];
end;

begin
  readln(s[1]);
  readln(s[2]);
  readln(n);
  m := 0;
  for i := 1 to n do begin
    readln(rs);
    add(rs[1], rs[4], rs[5]);
  end;
  ans := calc(length(s[1]), length(s[2]));
  if ans = inf then begin
    writeln(-1);
    halt(0);
  end;
  writeln(ans);
end.