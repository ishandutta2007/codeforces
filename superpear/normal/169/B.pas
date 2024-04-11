var s,st:ansistring;
    i,j,ls,lst:longint;
    a:array[0..10] of longint;
begin
  readln(s);
  readln(st);
  ls:=length(s);
  lst:=length(st);
  fillchar(a,sizeof(a),0);
  for i:=1 to lst do
    inc(a[ord(st[i])-48]);
  for i:=1 to ls do
    for j:=9 downto ord(s[i])-47 do
      if a[j]>0 then
        begin
          dec(a[j]);
          s[i]:=chr(j+48);
          break;
        end;
  writeln(s);
end.