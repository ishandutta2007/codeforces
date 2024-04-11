var n,i,j,ls,e,c1,c2:longint;
    s:string[12];
    f:array[0..100,0..100] of longint;
begin
  readln(n);
  for i:=0 to 26 do
    for j:=0 to 26 do
      f[i,j]:=-1;
  for i:=1 to n do
    begin
      readln(s);
      ls:=length(s);
      c1:=ord(s[1])-96;
      c2:=ord(s[ls])-96;
      for j:=1 to 26 do
        if (f[j,c1]<>-1) and (f[j,c1]+ls>f[j,c2]) then
          f[j,c2]:=f[j,c1]+ls;
      if ls>f[c1,c2] then f[c1,c2]:=ls;
    end;
  e:=0;
  for i:=1 to 26 do
    if f[i,i]>e then e:=f[i,i];
  writeln(e);
end.