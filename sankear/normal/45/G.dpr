program solution;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Math;

var
  n, i, j, z, sum : integer;
  p : array[0..6001] of boolean;

function check(x : integer) : boolean;
var i : integer;
begin
  result := true;
  i := 2;
  while i * i <= x do begin
    if x mod i = 0 then begin
      result := false;
      exit;
    end;
    inc(i);
  end;
end;

begin
  //reset(input, 'input.txt');
  //rewrite(output, 'output.txt');
  read(n);
  for i := 2 to n do
    p[i] := check(i);
  sum := 0;
  for i := 1 to n do
    sum := sum + i;
  if check(sum) then begin
    for i := 1 to n do
      write('1 ');
    halt(0);
  end;
  for i := 1 to n do
    if p[i] then begin
      sum := (n * (n + 1)) div 2 - i;
      if check(sum) then begin
        for j := 1 to n do
          if j = i then
            write('2 ')
          else
            write('1 ');
        halt(0);
      end;
    end;
  for i := 1 to n - 1 do
    for j := i + 1 to n do
      if (p[i]) and (p[j]) then begin
        sum := (n * (n + 1)) div 2 - i - j;
        if check(sum) then begin
          for z := 1 to n do
            if z = i then
              write('2 ')
            else
              if z = j then
                write('3 ')
              else
                write('1 ');
          halt(0);
        end;
      end;
end.