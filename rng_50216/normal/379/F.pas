
var pp : array[0 .. 22, 0 .. 1234567] of longint;
    de, p : array[0 .. 1234567] of longint;
    
function lca(v, u : longint) : longint;
var t, i : longint;
  begin
    if (de[v] > de[u]) then begin
      t := v;
      v := u;
      u := t;
    end;
    for i := 21 downto 0 do begin
      if (de[pp[i][u]] >= de[v]) then u := pp[i][u];
    end;
    if u = v then begin
      lca := u;
      exit;
    end;
    for i := 21 downto 0 do begin
      if pp[i][v] <> pp[i][u] then begin
        v := pp[i][v];
        u := pp[i][u];
      end;
    end;
    lca := p[v];
  end;

function dist(v, u : longint) : longint;
var t : longint;
  begin
    t := lca(v, u);
    dist := de[v] + de[u] - 2 * de[t];
  end;
  
var v, q, n, i, j, v1, v2, len, len1, len2 : longint;

begin
  p[1] := 1;
  p[2] := 1;
  p[3] := 1;
  p[4] := 1;
  read(q);
  n := 4;
  for i := 1 to q do begin
    read(v);
    inc(n);
    p[n] := v;
    inc(n);
    p[n] := v;
  end;
  de[1] := 0;
  for i := 2 to n do de[i] := de[p[i]] + 1;
  for i := 1 to n do pp[0][i] := p[i];
  for i := 1 to 21 do
    for j := 1 to n do pp[i][j] := pp[i - 1][pp[i - 1][j]];
  v1 := 2;
  v2 := 3;
  len := 2;
  for i := 5 to n do begin
    len1 := dist(i, v1);
    len2 := dist(i, v2);
    if (len1 >= len2) and (len1 > len) then begin
      len := len1;
      v2 := i;
    end else if (len2 > len) then begin
      len := len2;
      v1 := i;
    end;
    if not odd(i) then writeln(len);
  end;
end.