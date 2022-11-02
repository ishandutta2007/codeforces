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
  n, s, i, j : integer;
  a : array[0..5, 0..101] of char;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n);
  if n = 1 then begin
    writeln('a');
    writeln('a');
    writeln('b');
    writeln('b');
    halt;
  end;
  if n = 2 then begin
    writeln('aa');
    writeln('bb');
    writeln('cc');
    writeln('dd');
    halt;
  end;
  if n mod 2 = 0 then begin
    s := 1;
    i := 1;
    while i < n do begin
      if s = 1 then begin
        a[1, i] := 'a';
        a[1, i + 1] := 'a';
        a[2, i] := 'b';
        a[2, i + 1] := 'b';
        s := 2;
      end
      else begin
        a[1, i] := 'c';
        a[1, i + 1] := 'c';
        a[2, i] := 'd';
        a[2, i + 1] := 'd';
        s := 1;
      end;
      i := i + 2;
    end;
    a[3, 1] := 'e';
    a[4, 1] := 'e';
    s := 1;
    i := 2;
    while i < n do begin
      if s = 1 then begin
        a[3, i] := 'f';
        a[3, i + 1] := 'f';
        a[4, i] := 'g';
        a[4, i + 1] := 'g';
        s := 2;
      end
      else begin
        a[3, i] := 'h';
        a[3, i + 1] := 'h';
        a[4, i] := 'i';
        a[4, i + 1] := 'i';
        s := 1;
      end;
      i := i + 2;
    end;
    a[3, n] := 'z';
    a[4, n] := 'z';
  end
  else begin
    s := 1;
    i := 1;
    while i < n do begin
      if s = 1 then begin
        a[1, i] := 'a';
        a[1, i + 1] := 'a';
        a[2, i] := 'b';
        a[2, i + 1] := 'b';
        s := 2;
      end
      else begin
        a[1, i] := 'c';
        a[1, i + 1] := 'c';
        a[2, i] := 'd';
        a[2, i + 1] := 'd';
        s := 1;
      end;
      i := i + 2;
    end;
    a[3, 1] := 'e';
    a[4, 1] := 'e';
    s := 1;
    i := 2;
    while i < n do begin
      if s = 1 then begin
        a[3, i] := 'f';
        a[3, i + 1] := 'f';
        a[4, i] := 'g';
        a[4, i + 1] := 'g';
        s := 2;
      end
      else begin
        a[3, i] := 'h';
        a[3, i + 1] := 'h';
        a[4, i] := 'i';
        a[4, i + 1] := 'i';
        s := 1;
      end;
      i := i + 2;
    end;
    a[1, n] := 'z';
    a[2, n] := 'z';
  end;
  for i := 1 to 4 do begin
    for j := 1 to n do
      write(a[i, j]);
    writeln;
  end;
end.