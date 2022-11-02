program codeforces;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Math;

var
  i, j, z, k : integer;
  x1, x2, y1, y2 : array[1..4] of int64;

begin
  for i := 1 to 4 do begin
    read(x1[i], y1[i], x2[i], y2[i]);
    if (x1[i] - x2[i]) * (x1[i] - x2[i]) + (y1[i] - y2[i]) * (y1[i] - y2[i]) = 0 then begin
      write('NO');
      halt(0);
    end;
  end;
  for i := 1 to 4 do
    for j := 1 to 4 do
      for z := 1 to 4 do
        for k := 1 to 4 do begin
          if (i = j) or (i = z) or (i = k) or (j = z) or (j = k) or (z = k) then
            continue;
          if (x1[i] <> x2[i]) or (x1[j] <> x2[j]) or (y1[z] <> y2[z]) or (y1[k] <> y2[k]) then
            continue;
          if (x1[i] >= x1[j]) or (y1[z] >= y1[k]) then
            continue;
          if (min(y1[i], y2[i]) <> min(y1[j], y2[j])) or (max(y1[i], y2[i]) <> max(y1[j], y2[j])) or (min(x1[z], x2[z]) <> min(x1[k], x2[k])) or (max(x1[z], x2[z]) <> max(x1[k], x2[k])) then
            continue;
          if (x1[i] <> min(x1[z], x2[z])) or (x1[j] <> max(x1[z], x2[z])) or (x1[i] <> min(x1[k], x2[k])) or (x1[j] <> max(x1[k], x2[k])) then
            continue;
          if (y1[z] <> min(y1[i], y2[i])) or (y1[k] <> max(y1[i], y2[i])) or (y1[z] <> min(y1[j], y2[j])) or (y1[k] <> max(y1[j], y2[j])) then
            continue;
          write('YES');
          halt(0);
        end;
  write('NO');
end.