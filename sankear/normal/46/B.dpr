program solution;

{$APPTYPE CONSOLE}
{$MAXSTACKSIZE 100000000}
{$O+,R-,Q-}

uses
  SysUtils,
  Math;

var
  n, i, j, t : integer;
  s : string;
  a : array[0..5] of integer;
  nt : array[0..5] of string;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  nt[1] := 'S';
  nt[2] := 'M';
  nt[3] := 'L';
  nt[4] := 'XL';
  nt[5] := 'XXL';
  for i := 1 to 5 do
    read(a[i]);
  readln;
  readln(n);
  for i := 1 to n do begin
    readln(s);
    t := 0;
    for j := 1 to 5 do
      if nt[j] = s then begin
        t := j;
	break;
      end;
    for j := 0 to 4 do begin
      if (t + j <= 5) and (a[t + j] > 0) then begin
        writeln(nt[t + j]);
	dec(a[t + j]);
	break;
      end;
      if (t - j >= 1) and (a[t - j] > 0) then begin
        writeln(nt[t - j]);
	dec(a[t - j]);
	break;
      end;
    end; 
  end;
end.