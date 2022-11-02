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
  n, a, b, e, num, all, mask, i, j, z, t : integer;
  c : char;
  fl : boolean;
  sz : array[0..6] of integer;
  m, next1, next2 : array[0..6, 0..6] of integer;
  d : array[0..600001] of boolean;

procedure getc(var c : char);
begin
  read(c);
  while not (c in ['.', 'O']) do
    read(c);
end;

function good(a, b : integer) : boolean;
begin
  result := a and (1 shl (b - 1)) > 0;
end;

function add(a, b : integer) : integer;
begin
  result := a xor (1 shl (b - 1));
end;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  n := 0;
  sz[1] := 3;
  sz[2] := 4;
  sz[3] := 5;
  sz[4] := 4;
  sz[5] := 3;
  for i := 1 to 5 do
    for j := 1 to sz[i] do begin
      getc(c);
      if c = 'O' then begin
        inc(n);
        m[i, j] := n;
      end;
    end;
  next1[1, 1] := 1;
  next1[1, 2] := 2;
  next1[1, 3] := 3;
  next1[2, 1] := 1;
  next1[2, 2] := 2;
  next1[2, 3] := 3;
  next1[2, 4] := 4;
  next1[3, 2] := 1;
  next1[3, 3] := 2;
  next1[3, 4] := 3;
  next1[3, 5] := 4;
  next1[4, 2] := 1;
  next1[4, 3] := 2;
  next1[4, 4] := 3;
  next2[1, 1] := 2;
  next2[1, 2] := 3;
  next2[1, 3] := 4;
  next2[2, 1] := 2;
  next2[2, 2] := 3;
  next2[2, 3] := 4;
  next2[2, 4] := 5;
  next2[3, 1] := 1;
  next2[3, 2] := 2;
  next2[3, 3] := 3;
  next2[3, 4] := 4;
  next2[4, 1] := 1;
  next2[4, 2] := 2;
  next2[4, 3] := 3;
  all := 1 shl n - 1;
  for i := 1 to all do begin
    fl := false;
    for j := 1 to 5 do begin
      for z := 1 to sz[j] do begin
        a := m[j, z];
        if (a > 0) and (good(i, a)) then begin
          b := add(i, a);
          if not d[b] then begin
            fl := true;
            break;
          end;
          mask := b;
          for t := 1 to sz[j] do begin
            e := m[j, z + t];
            if (e > 0) and (good(i, e)) then begin
              mask := add(mask, e);
              if not d[mask] then begin
                fl := true;
                break;
              end;
            end
            else
              break;
          end;
          if fl then
            break;
          mask := b;
          num := next1[j, z];
          for t := 1 to 5 do begin
            e := m[j + t, num];
            if (e > 0) and (good(i, e)) then begin
              mask := add(mask, e);
              if not d[mask] then begin
                fl := true;
                break;
              end;
            end
            else
              break;
            num := next1[j + t, num];
          end;
          if fl then
            break;
          mask := b;
          num := next2[j, z];
          for t := 1 to 5 do begin
            e := m[j + t, num];
            if (e > 0) and (good(i, e)) then begin
              mask := add(mask, e);
              if not d[mask] then begin
                fl := true;
                break;
              end;
            end
            else
              break;
            num := next2[j + t, num];
          end;
          if fl then
            break;
        end;
      end;
      if fl then

        break;
    end;
    d[i] := fl;
  end;
  if d[all] then
    writeln('Karlsson')
  else
    writeln('Lillebror');
end.