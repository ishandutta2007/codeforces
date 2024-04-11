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
  n, k, all, mask, i, j, z, h : integer;
  cur : string;
  s : array[0..101] of string;
  a, b : array[0..18] of integer;
  sum : array[0..140001] of integer;
  can : array[0..18, 0..140001] of boolean;
  p : array[0..18, 0..140001] of integer;

procedure gets(var s : string);
var c : char;
begin
  s := '';
  read(c);
  while not (c in ['a'..'z', 'A'..'Z']) do
    read(c);
  while c in ['a'..'z', 'A'..'Z'] do begin
    s := s + c;
    read(c);
  end;
end;

procedure wrans(x, y : integer);
var k, i : integer;
begin
  if x > 1 then
    wrans(x - 1, p[x, y]);
  y := y xor p[x, y];
  k := 0;
  for i := 1 to n do
    if y and (1 shl (i - 1)) > 0 then begin
      inc(k);
      if k > 1 then
        write('+');
      write(s[a[i]]);
    end;
  write('->');
  writeln(s[b[x]]);
end;

begin
  //assign(input, 'input.txt'); reset(input);
  //assign(output, 'output.txt'); rewrite(output);
  s[1] := 'H';
  s[2] := 'He';
  s[3] := 'Li';
  s[4] := 'Be';
  s[5] := 'B';
  s[6] := 'C';
  s[7] := 'N';
  s[8] := 'O';
  s[9] := 'F';
  s[10] := 'Ne';
  s[11] := 'Na';
  s[12] := 'Mg';
  s[13] := 'Al';
  s[14] := 'Si';
  s[15] := 'P';
  s[16] := 'S';
  s[17] := 'Cl';
  s[18] := 'Ar';
  s[19] := 'K';
  s[20] := 'Ca';
  s[21] := 'Sc';
  s[22] := 'Ti';
  s[23] := 'V';
  s[24] := 'Cr';
  s[25] := 'Mn';
  s[26] := 'Fe';
  s[27] := 'Co';
  s[28] := 'Ni';
  s[29] := 'Cu';
  s[30] := 'Zn';
  s[31] := 'Ga';
  s[32] := 'Ge';
  s[33] := 'As';
  s[34] := 'Se';
  s[35] := 'Br';
  s[36] := 'Kr';
  s[37] := 'Rb';
  s[38] := 'Sr';
  s[39] := 'Y';
  s[40] := 'Zr';
  s[41] := 'Nb';
  s[42] := 'Mo';
  s[43] := 'Tc';
  s[44] := 'Ru';
  s[45] := 'Rh';
  s[46] := 'Pd';
  s[47] := 'Ag';
  s[48] := 'Cd';
  s[49] := 'In';
  s[50] := 'Sn';
  s[51] := 'Sb';
  s[52] := 'Te';
  s[53] := 'I';
  s[54] := 'Xe';
  s[55] := 'Cs';
  s[56] := 'Ba';
  s[57] := 'La';
  s[58] := 'Ce';
  s[59] := 'Pr';
  s[60] := 'Nd';
  s[61] := 'Pm';
  s[62] := 'Sm';
  s[63] := 'Eu';
  s[64] := 'Gd';
  s[65] := 'Tb';
  s[66] := 'Dy';
  s[67] := 'Ho';
  s[68] := 'Er';
  s[69] := 'Tm';
  s[70] := 'Yb';
  s[71] := 'Lu';
  s[72] := 'Hf';
  s[73] := 'Ta';
  s[74] := 'W';
  s[75] := 'Re';
  s[76] := 'Os';
  s[77] := 'Ir';
  s[78] := 'Pt';
  s[79] := 'Au';
  s[80] := 'Hg';
  s[81] := 'Tl';
  s[82] := 'Pb';
  s[83] := 'Bi';
  s[84] := 'Po';
  s[85] := 'At';
  s[86] := 'Rn';
  s[87] := 'Fr';
  s[88] := 'Ra';
  s[89] := 'Ac';
  s[90] := 'Th';
  s[91] := 'Pa';
  s[92] := 'U';
  s[93] := 'Np';
  s[94] := 'Pu';
  s[95] := 'Am';
  s[96] := 'Cm';
  s[97] := 'Bk';
  s[98] := 'Cf';
  s[99] := 'Es';
  s[100] := 'Fm';
  read(n, k);
  for i := 1 to n do begin
    gets(cur);
    for j := 1 to 100 do
      if cur = s[j] then begin
        a[i] := j;
        break;
      end;
  end;
  for i := 1 to k do begin
    gets(cur);
    for j := 1 to 100 do
      if cur = s[j] then begin
        b[i] := j;
        break;
      end;
  end;
  all := 1 shl n - 1;
  for i := 0 to all do
    for j := 1 to n do
      if i and (1 shl (j - 1)) > 0 then
        sum[i] := sum[i] + a[j];
  can[0, all] := true;
  for i := 1 to k do
    for j := 0 to all do begin
      if not can[i - 1, j] then
        continue;
      z := j;
      while z > 0 do begin
        if sum[z] = b[i] then begin
          mask := j xor z;
          can[i, mask] := true;
          p[i, mask] := j;
        end;
        z := (z - 1) and j;
      end;
    end;
  if not can[k, 0] then begin
    writeln('NO');
    halt(0);
  end;
  writeln('YES');
  wrans(k, 0);
end.