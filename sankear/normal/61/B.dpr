program solution;

{$APPTYPE CONSOLE}
{MODE DELPHI}
{$MAXSTACKSIZE 1000000000}
{O-,R+,Q-}
{$O+,R-,Q-}

uses
  SysUtils,
  Math;

const
  hx = 200003;

var
  n, k, i, j, z : integer;
  fh : int64;
  fl : boolean;
  s : string;
  pow : array[0..1001] of int64;
  len : array[0..31] of integer;
  h, hs : array[0..31] of int64;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  for i := 1 to 3 do begin
    readln(s);
    s := lowercase(s);
    h[i] := 0;
    len[i] := 0;
    for j := 1 to length(s) do
      if s[j] in ['a'..'z'] then begin
        h[i] := h[i] * hx + ord(s[j]);
        inc(len[i]);
      end;
  end;
  pow[0] := 1;
  for i := 1 to len[1] + len[2] + len[3] do
    pow[i] := pow[i - 1] * hx;
  k := 0;
  for i := 1 to 3 do
    for j := 1 to 3 do
      for z := 1 to 3 do
        if (i <> j) and (i <> z) and (j <> z) then begin
          inc(k);
          hs[k] := h[i] * pow[len[j] + len[z]] + h[j] * pow[len[z]] + h[z];
        end;
  readln(n);
  for i := 1 to n do begin
    readln(s);
    s := lowercase(s);
    fh := 0;
    for j := 1 to length(s) do
      if s[j] in ['a'..'z'] then
        fh := fh * hx + ord(s[j]);
    fl := false;
    for j := 1 to k do
      if hs[j] = fh then begin
        fl := true;
        break;
      end;
    if fl then
      writeln('ACC')
    else
      writeln('WA');
  end;
end.