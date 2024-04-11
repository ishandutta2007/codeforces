program Limak3;
var h, w, n, i, k, x1, x2, y1, y2: integer;
strokes: array [1..500] of string;
stroke_h, stroke_v: array [1..500] of array [1..501] of integer;
answers: array [1..100000] of integer;
begin
readln(h,w);
for i:=1 to h do readln(strokes[i]);
readln(n);
for i:=1 to h do
  begin
  stroke_h[i][1] := 0;
  for k:=2 to w do
    if (strokes[i][k-1] = '.') and (strokes[i][k] = '.') then stroke_h[i][k] := stroke_h[i][k-1]+1 else stroke_h[i][k]:=stroke_h[i][k-1];
  stroke_h[i][w+1] := stroke_h[i][w];
  end;
for i:=1 to w do
  begin
  stroke_v[i][1] := 0;
  for k:=2 to h do
    if (strokes[k-1][i] = '.') and (strokes[k][i] = '.') then stroke_v[i][k] := stroke_v[i][k-1]+1 else stroke_v[i][k]:=stroke_v[i][k-1];
  stroke_v[i][h+1] := stroke_v[i][h];
  end;
for i:=1 to n do
  begin
  answers[i] := 0;
  readln(x1,y1,x2,y2);
  for k:=x1 to x2 do
    answers[i] := answers[i] + stroke_h[k][y2] - stroke_h[k][y1];
  for k:=y1 to y2 do
    answers[i] := answers[i] + stroke_v[k][x2] - stroke_v[k][x1];
  end;
for i:=1 to n do
  writeln(answers[i]);
end.