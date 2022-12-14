var k, s, h: string;
    a: array[1..26] of integer;
    pr: array[1..200] of integer;
    u: array[1..1000] of integer;
    i, j, max, q, kol, w, ks, ko1, k1: longint;
    c: char;
begin

  //reset(input,'i.i');
  //rewrite(output,'o.o');


  readln(s);
  kol := 0;
  for i := 2 to length(s) do
  begin q := 0;
  for j := 1 to kol do
  if i mod pr[j] = 0 then
   q := 1;
  if q = 0 then begin inc(kol); pr[kol] := i;  end;
  end;


  for i := 1 to length(s) do
  inc(a[ord(s[i])-ord('a')+1]);

  max := 1;
  for i := 2 to 26 do if a[i] > a[max] then max := i;
  w := 0;

  c := chr(max + ord('a') - 1);
  for i := 1 to kol do if length(s) < pr[i]*2 then begin inc(w); u[pr[i]] := 1; end;
  if w+1 < length(s) - a[max] then begin write('NO'); halt; end;
  writeln('YES');
  kol := 0;
  ks := 0;
  h := '';
  k := '';
  inc(w);
  for i := 1 to length(s) do if (s[i] <> c)then
  begin inc(ks); h := h + s[i]; end else begin inc(kol); k := k + s[i]; end;
  k1 := 0;
  ko1 := 0;
  u[1] := 1;
  for i := 1 to w - ks do begin h := h + c; delete(k, 1,1); end;
  for i := 1 to length(s) do if u[i] = 0 then begin inc(ko1); write(k[ko1]); end
  else begin inc(k1); write(h[k1]); end;
end.