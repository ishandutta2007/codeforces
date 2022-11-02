program solution;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Math;

var
  k, i, p : integer;
  s : string;
  m : array[1..12] of string;

begin
  //reset(input, 'input.txt');
  //rewrite(output, 'output.txt');
  readln(s);
  read(k);
  m[1] := 'January';
  m[2] := 'February';
  m[3] := 'March';
  m[4] := 'April';
  m[5] := 'May';
  m[6] := 'June';
  m[7] := 'July';
  m[8] := 'August';
  m[9] := 'September';
  m[10] := 'October';
  m[11] := 'November';
  m[12] := 'December';
  for i := 1 to 12 do
    if m[i] = s then
      p := i;
  for i := 1 to k do begin
    inc(p);
    if p > 12 then
      p := 1;
  end;
  write(m[p]);
end.