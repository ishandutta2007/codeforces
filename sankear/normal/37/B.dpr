program solution;

{$APPTYPE CONSOLE}
{$O+,R-,Q-}

uses
  SysUtils,
  Math;

const
  eps = 0.000000001;
  maxt = 80000;

type
  tp = record
    p, d : integer;
  end;
  ts = record
    num, t : integer;
  end;

var
  n, t, i, k, max, reg, cur, dmg, res, num : integer;
  used : array[0..1001] of boolean;
  s : array[0..1001] of ts;
  p : array[0..1001] of tp;

begin
  //reset(input, 'input.txt');
  //rewrite(output, 'output.txt');
  read(n, max, reg);
  for i := 1 to n do
    read(p[i].p, p[i].d);
  cur := max;
  dmg := 0;
  for t := 0 to maxt do begin
    cur := cur - dmg;
    cur := min(cur + reg, max);
    if cur <= 0 then begin
      writeln('YES');
      writeln(t, ' ', k);
      for i := 1 to k do
        writeln(s[i].t, ' ', s[i].num);
      halt(0);
    end;
    res := 0;
    num := 0;
    for i := 1 to n do
      if (not used[i]) and (p[i].p - cur / max * 100 > -eps) and (p[i].d > res) then begin
        res := p[i].d;
        num := i;
      end;
    if num > 0 then begin
      dmg := dmg + res;
      used[num] := true;
      inc(k);
      s[k].num := num;
      s[k].t := t;
    end
    else
      if reg > dmg then
        break;
  end;
  write('NO');
end.