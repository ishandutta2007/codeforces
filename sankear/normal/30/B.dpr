program solution;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Math;

type
  tt = record
    v : array[1..3] of integer;
  end;

var
  s : string;
  t1, t2, t3 : tt;
  i, j, z : integer;

function getdate(s : string) : tt;
var i, k : integer;
begin
  result.v[1] := 0;
  result.v[2] := 0;
  result.v[3] := 0;
  k := 1;
  for i := 1 to length(s) do
    if s[i] = '.' then
      inc(k)
    else
      result.v[k] := result.v[k] * 10 + ord(s[i]) - ord('0');
end;

function correct(t : tt) : boolean;
var dm : array[1..12] of integer;
begin
  dm[1] := 31;
  dm[2] := 28;
  dm[3] := 31;
  dm[4] := 30;
  dm[5] := 31;
  dm[6] := 30;
  dm[7] := 31;
  dm[8] := 31;
  dm[9] := 30;
  dm[10] := 31;
  dm[11] := 30;
  dm[12] := 31;
  if t.v[3] mod 4 = 0 then
    inc(dm[2]);
  if (t.v[3] < 1) or (t.v[3] > 99) then begin
    result := false;
    exit;
  end;
  if (t.v[2] < 1) or (t.v[2] > 12) then begin
    result := false;
    exit;
  end;
  if (t.v[1] < 1) or (t.v[1] > dm[t.v[2]]) then begin
    result := false;
    exit;
  end;
  result := true;
end;

function check(t1, t2 : tt) : boolean;
begin
  if t2.v[3] - t1.v[3] < 18 then begin
    result := false;
    exit;
  end;
  if t2.v[3] - t1.v[3] = 18 then begin
    if t1.v[2] < t2.v[2] then begin
      result := true;
      exit;
    end;
    if t1.v[2] = t2.v[2] then begin
      if t1.v[1] <= t2.v[1] then begin
        result := true;
        exit;
      end;
      result := false;
      exit;
    end;
    result := false;
    exit;
  end;
  result := true;
end;

begin
  //reset(input, 'input.txt');
  //rewrite(output, 'output.txt');
  readln(s);
  t1 := getdate(s);
  readln(s);
  t2 := getdate(s);
  for i := 1 to 3 do
    for j := 1 to 3 do
      for z := 1 to 3 do
        if (i <> j) and (i <> z) and (j <> z) then begin
          t3.v[1] := t2.v[i];
          t3.v[2] := t2.v[j];
          t3.v[3] := t2.v[z];
          if (correct(t3)) and (check(t3, t1)) then begin
            write('YES');
            halt(0);
          end;
        end;
  write('NO');
end.