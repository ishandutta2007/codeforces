const ss:array[0..11] of string=('January','February','March','April','May','June','July','August','September','October','November','December');
var s:string;
    n,i:longint;
begin
  readln(s);
  for i:=0 to 11 do if ss[i]=s then n:=i;
  readln(i);
  writeln(ss[(n+i) mod 12]);
end.