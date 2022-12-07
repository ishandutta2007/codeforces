const
  maxn = 55;
var
  f:array[0..maxn, 0..maxn, 0..1] of int64;
  k,j,n,i,ne:longint;
  s:string;
  res:int64;
begin
  readln(s);
  for i:=0 to 9 do f[1, i, ord(chr(48+i) = s[1])]:=1;
  for i:=1 to length(s)-1 do for j:=0 to 9 do for k:=0 to 1 do if f[i, j, k]>0 then
  begin
    ne:=j+ord(s[i+1])-48;
    if ne and 1 = 0 then inc(f[i+1, ne shr 1, k and (ord(chr(ne shr 1+48) = s[i+1]))], f[i, j, k]) else
    begin
      inc(f[i+1, ne shr 1, k and (ord(chr(ne shr 1+48) = s[i+1]))], f[i, j, k]);
      if ne shr 1<9 then inc(f[i+1, ne shr 1+1, k and (ord(chr(ne shr 1+49) = s[i+1]))], f[i, j, k]);
    end;
  end;
  for i:=0 to 9 do inc(res, f[length(s), i, 0]);
  writeln(res);
end.