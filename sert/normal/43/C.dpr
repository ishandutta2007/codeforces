
var n, m, k, i, j: longint;
    o: array[0..2] of longint;
    s, t, y, fail: longint;
begin

  read(n);
  for i := 1 to n do
  begin
    read(t);
    inc(o[t mod 3]);
  end;
  j := o[0] div 2;
  if o[1] < o[2] then j := j + o[1] else j := j + o[2];
  write(j);
end.