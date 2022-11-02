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
  n, m, kol, a, i, j : integer;
  fl, can : boolean;
  used : array[0..201] of boolean;
  good : array[0..20001] of boolean;
  ex : array[0..20001, 0..201] of boolean;
  mem : array[0..20001] of integer;
  sz : array[0..201] of integer;
  b : array[0..201, 0..201] of integer;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n);
  m := (n * (n - 1)) div 2;
  for i := 1 to m do begin
    read(mem[i]);
    for j := 1 to mem[i] do begin
      read(a);
      ex[i, a] := true;
      used[a] := true;
    end;
  end;
  fl := false;
  for i := 1 to 200 do
    if used[i] then begin
      if not fl then begin
        for j := 1 to m do
          if ex[j, i] then begin
            good[j] := true;
            dec(mem[j]);
          end;
        inc(sz[1]);
        b[1, sz[1]] := i;
        fl := true;
      end
      else begin
        can := true;
        for j := 1 to m do
          if ((ex[j, i]) and (not good[j])) or ((not ex[j, i]) and (good[j])) then begin
            can := false;
            break;
          end;
        if can then begin
          for j := 1 to m do
            if (good[j]) and (mem[j] = 1) then begin
              can := false;
              break;
            end;
          if can then begin
            inc(sz[1]);
            b[1, sz[1]] := i;
            for j := 1 to m do
              if good[j] then
                dec(mem[j]);
          end;
        end;
      end;
    end;
  kol := 1;
  for i := 1 to m do begin
    can := true;
    for j := 1 to sz[1] do
      if not ex[i, b[1, j]] then begin
        can := false;
        break;
      end;
    if can then begin
      for j := 1 to sz[1] do
        ex[i, b[1, j]] := false;
      inc(kol);
      for j := 1 to 200 do
        if ex[i, j] then begin
          inc(sz[kol]);
          b[kol, sz[kol]] := j;
        end;
    end;
  end;
  for i := 1 to n do begin
    write(sz[i]);
    for j := 1 to sz[i] do
      write(' ', b[i, j]);
    writeln;
  end;
end.