program C105;

{$APPTYPE CONSOLE}

const eps = 0.0000001;

var s: string;
  vd, vp, m, l, k, d, kol, n, i, j, t, f, c: longint;
  x, xp: extended;

begin
  //reset(input,'i.i');
  //rewrite(output,'o.o');
  read(vp, vd, t, f, c);
  if (vd <= vp) then begin write(0); halt; end;
  xp := vp * t;
  xp := xp + (vp * xp) / (vd - vp);
  i := 0;
  while xp + eps < c do
  begin
    inc(i);
    xp := xp + vp * (f + xp / vd);
    xp := xp + (vp * xp) / (vd - vp);
  end;

  write(i);
end.