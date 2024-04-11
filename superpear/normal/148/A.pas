var a,b,c,d,i,n,s:longint;
begin
  read(a,b,c,d);
  readln(n);
  s:=0;
  for i:=1 to n do
    if (i mod a=0) or (i mod b=0) or (i mod c=0) or (i mod d=0) then
      inc(s);
  writeln(s);
end.