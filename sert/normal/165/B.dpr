Type Tdmas = array[1..200000] of longint;
Type Tmas = array[1..1000, 1..1000] of longint;

procedure Sort(a: Tdmas; l,r:longint);
var
  i,j,x,tmp: longint;
begin
  i:=l; j:=r;
  x:=a[l+random(r-l+1)];
  repeat
    while a[i] < x do inc(i);
    while x < a[j] do dec(j);
    if i <= j then
    begin
      tmp:=a[i]; a[i]:=a[j]; a[j]:=tmp;
      inc(i); dec(j);
    end;
  until i > j;
  if l < j then Sort(a, l,j);
  if i < r then Sort(a, i,r);
end;

function f(var v, k: longint): longint;
var ans, i, d: int64;
begin
  i := 1;
  ans := v;
  d := k;
  while trunc(v / d) > 0 do
  begin
    ans := ans + trunc(v / d);
    d := d * k;
  end;
  f := ans;
end;

var l, r, n, m, k, i, j, p, t, kol: longint;
    s, ss, str: string;
    x, y, u, a, b, c: Tdmas;
    un, us, ue, uw: boolean;


begin
  //reset(input,'i.i');
  //rewrite(output,'o.o');
  read(n, k);
  randomize;
  l := 1;
  r := 2000000000;
  while r > l do
  begin
    m := (l + r + random(100) mod 2) div 2;
    p := f(m, k);
    if p < n then l := m + 1;
    if p = n then r := m;
    if p > n then r := m;
  end;
  write(r);
end.