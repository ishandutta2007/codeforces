program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  N, K, I, Mn, Sm: Integer;
  A, Count: array [1..100] of Integer;
  Used: array [1..100] of Boolean;

begin
  reset(input, 'input.txt'); rewrite(output, 'output.txt');
  readln(N, K);
  for I := 1 to N do
    read(A[I]);
  readln;
  for I := 1 to N do Count[I] := 0;
  for I := 1 to N do Used[i] := False;
  while True do
    begin
      Mn := -1;
      for I := 1 to N do
        if (not Used[I]) and ((Mn = -1) or (A[Mn] < A[I])) then
          Mn := I;
      if Mn = -1 then
        break;
      if (A[Mn] < K) or (Count[Mn] >= 3) then
        begin
          Used[Mn] := True;
          continue;
        end;
      Inc(Count[Mn]);
      Dec(A[Mn], K);
    end;
  Sm := 0;
  for I := 1 to N do
    if Used[I] then
      Inc(Sm, A[I]);
  writeln(Sm);
  close(input); close(output);
end.