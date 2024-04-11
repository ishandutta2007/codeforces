program africand;

{$APPTYPE CONSOLE}

function str (var s: string; l, r: integer): string;
var i: longint; ss: string;
begin
  ss := '';
  for i := l to r do ss := ss + s[i];
  str := ss;
end;

var x, a, b, c, i, k, low, hi, j, max, y: longint;
    d : array [1..100] of string;
    r: array[1..100] of longint;
    nama, s, sb, sc: string;
    code: integer;

begin
//reset(input,'i.i');
//rewrite(output,'o.o');
  hi := 0;
  c := 0;
  read(nama);
  readln(k);
  for i := 1 to k do
  begin
    c := 0;
    readln(s);
    x := 1;
    while s[x] <> ' ' do inc(x);
    sb := str(s, 1, x - 1);
    inc(x); 
    if s[x] = 'l' then begin b := 5; a := x + 6; end;
    if s[x] = 'c' then begin b := 10; a := x + 13; end;
    if s[x] = 'p' then begin b := 15; a := x + 10; end;
    x := a;
    while s[x] <> '''' do inc(x);
    sc := str(s, a, x - 1);
    if (sb = nama) or (sc = nama) then
    begin
      y := -1;
      if sc = nama then sc := sb;
      for j := 1 to hi do
        if d[j] = sc then y := j;
      if y = -1 then begin inc(hi); y := hi; d[hi] := sc; end;
      r[y] := r[y] + b;
    end else begin
      y := -1;
      for j := 1 to hi do
        if d[j] = sc then y := j;
      if y = -1 then begin inc(hi); y := hi; d[hi] := sc; end;

      y := -1;
      for j := 1 to hi do
        if d[j] = sb then y := j;
      if y = -1 then begin inc(hi); y := hi; d[hi] := sb; end;
      
    end;
  end;
  for i := 1 to hi - 1 do for j := 1 to hi - 1 do
  if (r[j] < r[j + 1]) or ((r[j] = r[j + 1]) and (d[j] > d[j + 1])) then
  begin
    s := d[j];
    d[j] := d[j + 1];
    d[j + 1] := s;
    a := r[j]; r[j] := r[j + 1]; r[j + 1] := a;
  end;
  for i := 1 to hi do writeln(d[i]);
end.