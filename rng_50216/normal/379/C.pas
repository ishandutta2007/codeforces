
uses Math;

var a, id, ans : array[0 .. 1234567] of longint;

procedure sort(l, r : longint);
var t, i, j, x : longint;
  begin
    if (l >= r) then exit;
    i := l;
    j := r;
    x := a[id[random(r - l + 1) + l]];
    while (i <= j) do begin
      while (a[id[i]] < x) do inc(i);
      while (a[id[j]] > x) do dec(j);
      if (i <= j) then begin
        t := id[i];
        id[i] := id[j];
        id[j] := t;
        inc(i);
        dec(j);
      end;
    end;
    sort(i, r);
    sort(l, j);
  end;
  
var n, i, last : longint;
  
begin
  randomize;
  read(n);
  for i := 1 to n do begin
    read(a[i]);
    id[i] := i;
  end;
  sort(1, n);
  last := -maxlongint;
  for i := 1 to n do begin
    ans[id[i]] := max(a[id[i]], last + 1);
    last := ans[id[i]];
  end;
  for i := 1 to n do begin
    if (i > 1) then write(' ');
    write(ans[i]);
  end;
  writeln;
end.