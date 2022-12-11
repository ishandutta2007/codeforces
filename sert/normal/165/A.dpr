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

var n, m, k, i, j, p, t, kol: longint;
    s, ss, str: string;
    x, y, u, a, b, c: Tdmas;
    un, us, ue, uw: boolean;


begin
  //reset(input,'i.i');
  //rewrite(output,'o.o');
  read(n);
  kol := 0;
  for i := 1 to n do read(x[i], y[i]);
  for i := 1 to n do
  begin
    un := false;
    uw := false;
    ue := false;
    us := false;
    for j := 1 to n do
    begin
      if (x[j] = x[i]) and (y[j] > y[i]) then un := true;
      if (x[j] = x[i]) and (y[j] < y[i]) then us := true;
      if (x[j] < x[i]) and (y[j] = y[i]) then ue := true;
      if (x[j] > x[i]) and (y[i] = y[j]) then uw := true;
    end;
    if (un) and (us) and (uw) and (ue) then inc(kol);
  end;
  write(kol);
end.