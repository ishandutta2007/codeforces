Type Tdmas = array[1..200000] of longint;
Type Tmas = array[1..1000, 1..1000] of longint;

procedure Sort(var a, u: Tdmas; l,r:longint);
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
      tmp := u[i]; u[i] := u[j]; u[j] := tmp;
      inc(i); dec(j);
    end;
  until i > j;
  if l < j then Sort(a, u, l, j);
  if i < r then Sort(a, u,i,r);
end;

var n, m, k, i, j, p, t, x, y, pos, kol, pz: longint;
    s, ss, str: string;
    u, a, b, c, d, ua, ub: Tdmas;
    u1, u2: boolean;

begin
  //reset(input,'i.i');
  //rewrite(output,'o.o');
  randomize;
  read(n, m, x, y);
  fillchar(c, sizeof(c), 0);
  fillchar(d, sizeof(d), 0);
  for i := 1 to n do ua[i] := i;
  for i := 1 to m do ub[i] := i;
  for i := 1 to n do read(a[i]);
  for i := 1 to m do read(b[i]);
  sort(a, ua, 1, n);
  sort(b, ub, 1, m);
  kol := 0;
  pos := 1;
  pz := 1;
  u1 := false;
  u2 := true;
  while (pos <= n) and (pz <= m) do
  begin
    while (pz <= m) and (b[pz] < a[pos] - x) do begin inc(pz); u1 := true; end;
    if (b[pz] <= a[pos] + y) and (pz <= m) then
    begin inc(kol); c[kol] := ua[pos]; d[kol] := ub[pz]; inc(pz); u2 := true; end;
    inc(pos);
  end;
  writeln(kol);
  for i := 1 to kol do writeln(c[i], ' ',d[i]);



end.