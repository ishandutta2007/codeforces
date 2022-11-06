program Falcifications;
var max, nmax, n, m, i, k, tmp: integer;
votes: array [1..100] of integer;
begin
readln(n,m);
for i:=1 to n do
  votes[i]:=0;
for i:=1 to m do
  begin
  max:=-1;
  for k:=1 to n do
    begin
    read(tmp);
    if (tmp>max) then begin
      max:=tmp;
      nmax:=k;
      end;
    end;
  votes[nmax]:=votes[nmax]+1;
  end;
max:=-1;
for i:=1 to n do
  if votes[i]>max then
    begin
    max:=votes[i];
    nmax:=i;
    end;
writeln(nmax);
end.