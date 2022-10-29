program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

type
  trec = record
    d, min: longint;
  end;
var
  N, m, k, i, j, min, kmin: integer;
  l: array [1..100] of trec;
  d, mina: array [1..100] of longint;
begin
  read(n, m, k);
  for i := 1 to m do begin
    read(l[i].d);
    l[i].min := 0;
  end;
  for i := 1 to k do
    read(d[i]);

  kmin := 1;
  min := 1000000100;
  for i := 1 to m do begin
    for j := 1 to k do
      if d[j] mod l[i].d = 0 then
        inc(l[i].min);
    if l[i].min < min then begin
      min := l[i].min;
      kmin := 1;
      mina[1] := i;
    end else
    if l[i].min = min then begin
      inc(kmin);
      mina[kmin] := i;
    end;
  end;

  writeln(kmin);
  for i := 1 to kmin do
    write(mina[i], ' ');

end.