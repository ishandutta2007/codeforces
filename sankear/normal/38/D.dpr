program solution;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Math;

const
  eps = 0.000000001;

type
  tp = record
    x1, y1, x2, y2, m : extended;
  end;

var
  n, i, j : integer;
  fl : boolean;
  xm, ym, m : extended;
  p : array[0..101] of tp;

function check(p : tp; x, y : extended) : boolean;
begin
  result := (x - min(p.x1, p.x2) > -eps) and (max(p.x1, p.x2) - x > -eps) and (y - min(p.y1, p.y2) > -eps) and (max(p.y1, p.y2) - y > -eps);
end;

begin
  //reset(input, 'input.txt');
  //rewrite(output, 'output.txt');
  read(n);
  for i := 1 to n do
    read(p[i].x1, p[i].y1, p[i].x2, p[i].y2);
  for i := 1 to n do
    p[i].m := abs(p[i].x1 - p[i].x2) * abs(p[i].x1 - p[i].x2) * abs(p[i].x1 - p[i].x2);
  for i := 2 to n do begin
    xm := p[i].m * (p[i].x1 + p[i].x2) / 2;
    ym := p[i].m * (p[i].y1 + p[i].y2) / 2;
    m := p[i].m;
    fl := true;
    for j := i - 1 downto 1 do begin
      if not check(p[j], xm / m, ym / m) then begin
        fl := false;
        break;
      end;
      xm := xm + p[j].m * (p[j].x1 + p[j].x2) / 2;
      ym := ym + p[j].m * (p[j].y1 + p[j].y2) / 2;
      m := m + p[j].m;
    end;
    if not fl then begin
      write(i - 1);
      halt(0);
    end;
  end;
  write(n);
end.