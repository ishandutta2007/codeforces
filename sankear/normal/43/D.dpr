program solution;

{$APPTYPE CONSOLE}
{$MAXSTACKSIZE 100000000}
{$O+,R-,Q-}

uses
  SysUtils,
  Math;

var
  n, m, i, j : integer;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n, m);
  if n = 1 then begin
    if m = 2 then begin
      writeln(0);
      writeln('1 1');
      writeln('1 2');
      writeln('1 1');
      halt(0);
    end;
    writeln(1);
    writeln('1 ', m, ' 1 1');
    for i := 1 to m do
      writeln('1 ', i);
    writeln('1 1');
    halt(0);
  end;
  if m = 1 then begin
    if n = 2 then begin
      writeln(0);
      writeln('1 1');
      writeln('2 1');
      writeln('1 1');
      halt(0);
    end;
    writeln(1);
    writeln(n, ' 1 1 1');
    for i := 1 to n do
      writeln(i, ' 1');
    writeln('1 1');
    halt(0);
  end;
  if n mod 2 = 0 then begin
    writeln(0);
    for i := 1 to m do
      writeln('1 ', i);
    for i := 2 to n do
      if i mod 2 = 0 then begin
        for j := m downto 2 do
	  writeln(i, ' ', j);
      end
      else begin
        for j := 2 to m do
	  writeln(i, ' ', j);
      end;
    for i := n downto 1 do
      writeln(i, ' 1');
    halt(0);
  end;
  if m mod 2 = 0 then begin
    writeln(0);
    for i := 1 to n do
      writeln(i, ' 1');
    for i := 2 to m do
      if i mod 2 = 0 then begin
        for j := n downto 2 do
	  writeln(j, ' ', i);
      end
      else begin
        for j := 2 to n do
	  writeln(j, ' ', i);
      end;
    for i := m downto 1 do
      writeln('1 ', i);
    halt(0);
  end;
  writeln(1);
  writeln(n, ' ', m, ' 1 1');
  for i := 1 to n do
    if i mod 2 = 1 then begin
      for j := 1 to m do
        writeln(i, ' ', j);
    end
    else begin
      for j := m downto 1 do
        writeln(i, ' ', j);
    end;
  writeln('1 1');
end.