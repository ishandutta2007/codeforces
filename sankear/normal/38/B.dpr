program solution;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  s1, s2 : string;
  ans, x1, y1, x2, y2, i, j : integer;
  used : array[0..9, 0..9] of boolean;

begin
  //reset(input, 'input.txt');
  //rewrite(output, 'output.txt');
  readln(s1);
  readln(s2);
  x1 := 9 - ord(s1[2]) + ord('0');
  y1 := ord(s1[1]) - ord('a') + 1;
  x2 := 9 - ord(s2[2]) + ord('0');
  y2 := ord(s2[1]) - ord('a') + 1;
  used[x1, y1] := true;
  used[x2, y2] := true;
  ans := 0;
  for i := 1 to 8 do
    for j := 1 to 8 do
      if not used[i, j] then begin
        if (i = x1) or (j = y1) or ((abs(i - x2) > 0) and (abs(j - y2) > 0) and (abs(i - x2) + abs(j - y2) = 3)) or ((abs(i - x1) > 0) and (abs(j - y1) > 0) and (abs(i - x1) + abs(j - y1) = 3)) then
          continue;
        inc(ans);
      end;
  write(ans);
end.