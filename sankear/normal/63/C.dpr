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
  n, i, j, a, z, h, x, y, t, k, bb, cc : integer;
  fl : boolean;
  s, w : string;
  zz : array[0..11] of string;
  b, c : array[0..11] of integer;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  read(n);
  for i := 1 to n do begin
    read(a, b[i], c[i]);
    zz[i] := inttostr(a);
    while length(zz[i]) < 4 do
      zz[i] := '0' + zz[i];
  end;
  k := 0;
  for i := 0 to 9 do
    for j := 0 to 9 do
      for z := 0 to 9 do
        for h := 0 to 9 do
          if (i <> j) and (i <> z) and (i <> h) and (j <> z) and (j <> h) and (z <> h) then begin
            w := inttostr(i) + inttostr(j) + inttostr(z) + inttostr(h);
            fl := true;
            for x := 1 to n do begin
              bb := 0;
              cc := 0;
              for y := 1 to 4 do
                if w[y] = zz[x, y] then
                  inc(bb);
              for t := 1 to 4 do
                for y := 1 to 4 do
                  if (y <> t) and (w[y] = zz[x, t]) then begin
                    inc(cc);
                    break;
                  end;
              if (bb <> b[x]) or (cc <> c[x]) then begin
                fl := false;
                break;
              end;
            end;
            if fl then begin
              inc(k);
              s := w;
            end;
          end;
  if k = 0 then begin
    writeln('Incorrect data');
    halt(0);
  end;
  if k > 1 then begin
    writeln('Need more data');
    halt(0);
  end;
  writeln(s);
end.