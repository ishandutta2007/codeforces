var l, kol, nom, resh: array[1..100] of longint;
    n, i, j, p, r, k: longint;

begin
  read(n);
  for i := 1 to n do
  begin
    nom[i] := i;
    read(l[i], r);
    kol[i] := r - l[i] + 1;
  end;

  for i := 1 to n - 1 do
  for j := 1 to n - i do
  if l[j] >l[j+1] then
  begin
  p := l[j];
  l[j] := l[j + 1];
  l[j + 1] := p;

  p := kol[j];
  kol[j] := kol[j + 1];
  kol[j + 1] := p;

  p := nom[j];
  nom[j] := nom[j + 1];
  nom[j + 1] := p;
  end;

  for i := 1 to n do
  for j := 1 to (n - 1) do
  if (l[j] = l[j+1]) and (kol[j]>kol[j + 1]) then
  begin
  p := nom[j];
  nom[j] := nom[j + 1];
  nom[j + 1] := p;

  p := kol[j];
  kol[j] := kol[j + 1];
  kol[j + 1] := p;
  end;


  for i := 1 to n do
  begin
    resh[i] := l[i];

    j := i + 1;
    while l[j] = l[i] do
    begin
      l[j] := l[j] + 1;
      kol[j] := kol[j] - 1;
      inc(j);
    end;

    for k := i + 1 to n do
    for j := i + 1 to n - 1 do
    if (l[j] = l[j+1]) and (kol[j]>kol[j + 1]) then
    begin
      p := nom[j];
      nom[j] := nom[j + 1];
      nom[j + 1] := p;

      p := kol[j];
      kol[j] := kol[j + 1];
      kol[j + 1] := p;
    end;

  end;
  for j := 1 to n do
  for i := 1 to n do
  if nom[i] =j then write(resh[i], ' ');

end.