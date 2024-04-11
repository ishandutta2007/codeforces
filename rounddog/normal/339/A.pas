
program cf1;

var
    s:string;
    a:array[1..3] of longint;
    i,j,k,l,m,n:longint;

begin
  readln(s);
  l:=(length(s)+1) div 2;
  for i:= 1 to l do
    inc(a[ord(s[I*2-1])-48]);
  s:='';
  for i:= 1 to 3 do
    for j:= 1 to a[i] do
      s:=s+chr(48+i)+'+';
  for i:= 1 to length(s)-1 do
    write(s[i]);
  writeln;
end.