program a106;

{$APPTYPE CONSOLE}

type tdmas = array[1..100000] of longint;

var
    kf, ks, n, k, i, j, t: longint;
    sf, ss: int64;
    f, s, a, b: Tdmas;
    sys: array[1..50] of char;

procedure qsort(var a: Tdmas; l, r: longint);
var x, i, j, h: longint;
begin
  i := l;
  j := r;
  x := a[l + random(r - l + 1)];
  repeat
    while a[i] < x do inc(i);
    while a[j] > x do dec(j);
    if i <= j then
    begin
      h := a[i]; a[i] := a[j]; a[j] := h;
      h := b[i]; b[i] := b[j]; b[j] := h;
      inc(i);
      dec(j);
    end;
  until i > j;
  if i < r then qsort(a, i, r);
  if j > l then qsort(a, l, j);
end;


begin
  randomize;
  //reset(input,'i.i');
  //rewrite(output,'o.o');
  read(n);
  for i := 1 to n do
    read(a[i]);
  for i := 1 to n do b[i] := i;
  qsort(a, 1, n);
  sf := a[n]; ss := 0; ks := 0; kf := 1;
  f[1] := b[n];
  if n mod 2 = 0 then
  begin
    ks := 1;
    ss := a[n - 1];
    s[1] := b[n - 1];
  end;
  for i := (n - 1) div 2 downto 1 do
  begin
    inc(ks);
    inc(kf);
    if ss < sf then
    begin
      s[ks] := b[i * 2];
      f[kf] := b[i * 2 - 1];
      ss := ss + a[i * 2];
      sf := sf + a[i * 2 - 1];
    end
    else
    begin
      s[ks] := b[i * 2 - 1];
      f[kf] := b[i * 2];
      ss := ss + a[i * 2 - 1];
      sf := sf + a[i * 2];
    end;
  end;
  writeln(kf);
  for i := 1 to kf do write(f[i], ' ');
  writeln;
  writeln(ks);
  for i := 1 to ks do write(s[i], ' '); 


end.