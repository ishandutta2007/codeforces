program solution;

{$APPTYPE CONSOLE}
{MODE DELPHI}
{$MAXSTACKSIZE 1000000000}
{O-,R+,Q+}
{$O+,R-,Q-}

uses
  SysUtils,
  Math;

var
  n, m, x1, y1, x2, y2, i, j, z, h : integer;
  c : char;
  x, y : array[0..3] of integer;
  use : array[0..5] of integer;
  ex : array[0..14] of boolean;
  used : array[0..14, 0..5] of boolean;
  bad : array[0..18, 0..18] of boolean;
  a, b, col : array[0..18, 0..18] of integer;

procedure getc(var c : char);
begin
  read(c);
  while not (c in ['0'..'9', 'A'..'Z']) do
    read(c);
end;

function check(x, y : integer) : boolean;
var i, j : integer;
begin
  result := false;
  for i := 1 to 4 do
    use[i] := 0;
  for i := x to x + 2 do
    for j := y to y + 2 do
      inc(use[b[i, j]]);
  for i := 1 to 4 do
    if use[i] = 9 then begin
      result := true;
      exit;
    end;
  for i := 1 to 13 do
    ex[i] := false;
  for i := x to x + 2 do
    for j := y to y + 2 do begin
      if ex[a[i, j]] then
        exit;
      ex[a[i, j]] := true;
    end;
  result := true;
end;

function good() : boolean;
var i, j, z, h, x, y, op : integer;
fl : boolean;
begin
  result := false;
  op := 0;
  for i := 1 to n do
    for j := 1 to m do
      col[i, j] := 0;
  for i := 1 to n - 2 do
    for j := 1 to m - 2 do
      for z := 1 to n - 2 do
        for h := 1 to m - 2 do begin
          inc(op);
          for x := i to i + 2 do
            for y := j to j + 2 do
              col[x, y] := op;
          fl := true;
          for x := z to z + 2 do
            for y := h to h + 2 do
              if col[x, y] = op then
                fl := false;
          if (fl) and (check(i, j)) and (check(z, h)) then begin
            x1 := i;
            y1 := j;
            x2 := z;
            y2 := h;
            result := true;
            exit;
          end;
        end;
end;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n, m);
  for i := 1 to n do
    for j := 1 to m do begin
      getc(c);
      if c in ['0'..'9'] then
        a[i, j] := ord(c) - ord('1')
      else
        if c = 'T' then
          a[i, j] := 9
        else
          if c = 'J' then
            a[i, j] := 10
          else
            if c = 'Q' then
              a[i, j] := 11
            else
              if c = 'K' then
                a[i, j] := 12
              else
                a[i, j] := 13;
      getc(c);
      if c in ['0'..'9'] then begin
        bad[i, j] := true;
        b[i, j] := ord(c) - ord('0');
      end
      else
        if c = 'C' then
          b[i, j] := 1
        else
          if c = 'D' then
            b[i, j] := 2
          else
            if c = 'H' then
              b[i, j] := 3
            else
              b[i, j] := 4;
    end;
  for i := 1 to n do
    for j := 1 to m do
      if not bad[i, j] then
        used[a[i, j], b[i, j]] := true;
  for i := 1 to n do
    for j := 1 to m do
      if bad[i, j] then begin
        x[b[i, j]] := i;
        y[b[i, j]] := j;
      end;
  if (x[1] = 0) and (y[1] = 0) and (x[2] = 0) and (y[2] = 0) then begin
    if good() then begin
      writeln('Solution exists.');
      writeln('There are no jokers.');
      writeln('Put the first square to (', x1, ', ', y1, ').');
      writeln('Put the second square to (', x2, ', ', y2, ').');
    end
    else
      writeln('No solution.');
    halt(0);
  end;
  if (x[1] = 0) and (y[1] = 0) and (x[2] > 0) and (y[2] > 0) then begin
    for i := 1 to 13 do
      for j := 1 to 4 do
        if not used[i, j] then begin
          a[x[2], y[2]] := i;
          b[x[2], y[2]] := j;
          if good() then begin
            writeln('Solution exists.');
            write('Replace J2 with ');
            if i < 9 then
              write(i + 1)
            else
              if i = 9 then
                write('T')
              else
                if i = 10 then
                  write('J')
                else
                  if i = 11 then
                    write('Q')
                  else
                    if i = 12 then
                      write('K')
                    else
                      write('A');
            if j = 1 then
              write('C')
            else
              if j = 2 then
                write('D')
              else
                if j = 3 then
                  write('H')
                else
                  write('S');
            writeln('.');
            writeln('Put the first square to (', x1, ', ', y1, ').');
            writeln('Put the second square to (', x2, ', ', y2, ').');
            halt(0);
          end;
        end;
    writeln('No solution.');
    halt(0);
  end;
  if (x[1] > 0) and (y[1] > 0) and (x[2] = 0) and (y[2] = 0) then begin
    for i := 1 to 13 do
      for j := 1 to 4 do
        if not used[i, j] then begin
          a[x[1], y[1]] := i;
          b[x[1], y[1]] := j;
          if good() then begin
            writeln('Solution exists.');
            write('Replace J1 with ');
            if i < 9 then
              write(i + 1)
            else
              if i = 9 then
                write('T')
              else
                if i = 10 then
                  write('J')
                else
                  if i = 11 then
                    write('Q')
                  else
                    if i = 12 then
                      write('K')
                    else
                      write('A');
            if j = 1 then
              write('C')
            else
              if j = 2 then
                write('D')
              else
                if j = 3 then
                  write('H')
                else
                  write('S');
            writeln('.');
            writeln('Put the first square to (', x1, ', ', y1, ').');
            writeln('Put the second square to (', x2, ', ', y2, ').');
            halt(0);
          end;
        end;
    writeln('No solution.');
    halt(0);
  end;
  for i := 1 to 13 do
    for j := 1 to 4 do
      for z := 1 to 13 do
        for h := 1 to 4 do
          if ((i <> z) or (j <> h)) and (not used[i, j]) and (not used[z, h]) then begin
            a[x[1], y[1]] := i;
            b[x[1], y[1]] := j;
            a[x[2], y[2]] := z;
            b[x[2], y[2]] := h;
            if good() then begin
              writeln('Solution exists.');
              write('Replace J1 with ');
              if i < 9 then
                write(i + 1)
              else
                if i = 9 then
                  write('T')
                else
                  if i = 10 then
                    write('J')
                  else
                    if i = 11 then
                      write('Q')
                    else
                      if i = 12 then
                        write('K')
                      else
                        write('A');
              if j = 1 then
                write('C')
              else
                if j = 2 then
                  write('D')
                else
                  if j = 3 then
                    write('H')
                  else
                    write('S');
              write(' and J2 with ');
              if z < 9 then
                write(z + 1)
              else
                if z = 9 then
                  write('T')
                else
                  if z = 10 then
                    write('J')
                  else
                    if z = 11 then
                      write('Q')
                    else
                      if z = 12 then
                        write('K')
                      else
                        write('A');
              if h = 1 then
                write('C')
              else
                if h = 2 then
                  write('D')
                else
                  if h = 3 then
                    write('H')
                  else
                    write('S');
              writeln('.');
              writeln('Put the first square to (', x1, ', ', y1, ').');
              writeln('Put the second square to (', x2, ', ', y2, ').');
              halt(0);
            end;
          end;
  writeln('No solution.');
end.