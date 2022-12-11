program a100a;

{$APPTYPE CONSOLE}

uses math;

const eps = 0.000000001;

var r, r1, n: longint;
    yg: extended;

begin
  //reset(input,'i.i');
  //rewrite(output,'o.o');
  read(n, r, r1);
  if r1 > r then begin write('NO'); halt; end;
  if r < 2 * r1 - eps then yg := pi else
    yg := arcsin(r1 / (r - r1));
  if n * yg - eps < pi then write('YES') else write('NO');
end.