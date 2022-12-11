program dinamka;

{$APPTYPE CONSOLE}

var s1, s: array[1..100] of string [105];
    n, k, i, j, u: longint;
    st, iz: string;
begin

readln(st);
readln(n);
iz := st;
for i := 1 to n do begin readln(s[i]);
if length(st)>length(s[i]) then s1[i] := '!@#$%^@$#@&@%$#@' else
for j := 1 to length(st) do s1[i] := s1[i] + s[i][j]; end;
for i := 1 to n do
if (s1[i] = iz) and ((u=0)or(s[i]<st)) then
begin
  st := s[i];
  u := 1;
end;
writeln(st);

end.